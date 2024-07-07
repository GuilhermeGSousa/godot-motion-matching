#include "gd_imgui.h"

#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void GdImGui::_enter_tree() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    shader = ResourceLoader::get_singleton()->load("res://addons/motion_matching/shaders/gui_shader.gdshader");

    material.instantiate();
    material->set_shader(shader);

    set_texture_filter(TEXTURE_FILTER_LINEAR);
    set_texture_repeat(TEXTURE_REPEAT_ENABLED);
    set_light_mask(0);

    RenderingServer* rs = RenderingServer::get_singleton();
    rs->connect("frame_pre_draw", Callable(this, "Impl_BeginFrame"));
    rs->connect("frame_post_draw", Callable(this, "Impl_EndFrame"));

    Impl_Init();
}

void GdImGui::_exit_tree() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    Impl_Shutdown();
}

void GdImGui::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    set_process_priority(std::numeric_limits<int32_t>::min());
    set_process_mode(Node::PROCESS_MODE_ALWAYS);
}

void GdImGui::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
}

void GdImGui::_bind_methods() {

    ClassDB::bind_method(D_METHOD("Impl_BeginFrame"), &GdImGui::Impl_BeginFrame);
    ClassDB::bind_method(D_METHOD("Impl_EndFrame"), &GdImGui::Impl_EndFrame);
}

Control* GdImGui::get_next_child() {
    while (this->get_child_count() <= nextFreeChild) {
        auto c = memnew(Control());
        c->set_material(material->duplicate());
        add_child(c);
    }
    auto ret = (Control*)(this->get_child(nextFreeChild));
    ++nextFreeChild;
    return ret;
}

void GdImGui::Impl_NewFrame() {
    ImGuiIO& io = ImGui::GetIO();

    DisplayServer* ds = DisplayServer::get_singleton();

    auto s = ds->window_get_size(0);
    int w = s.width;
    int h = s.height;
    io.DisplaySize = ImVec2((float)w, (float)h);

    auto now = std::chrono::steady_clock::now();
    double dt = std::chrono::duration<double>(now - prev_frame_start).count();
    prev_frame_start = now;
    io.DeltaTime = dt;
}

void GdImGui::Impl_Init() {
    IMGUI_CHECKVERSION();
    imGuiContext = ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.BackendPlatformUserData = this;
    ImGui::StyleColorsClassic();

    Impl_InitFonts();
}

void GdImGui::Impl_InitFonts() {
    ImGuiIO& io = ImGui::GetIO();

    unsigned char* pixels;
    int width, height;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    PackedByteArray pixel_array;
    pixel_array.resize(width * height * 4);
    memcpy((void*)pixel_array.ptr(), pixels, width * height * 4);

    Ref<Image> image;
    image.instantiate();
    image->set_data(width, height, false, Image::Format::FORMAT_RGBA8, pixel_array);

    font_texture = ImageTexture::create_from_image(image);
    io.Fonts->SetTexID((ImTextureID)(intptr_t)font_texture.ptr());
}

void GdImGui::Impl_Shutdown() {
    ImGuiIO& io = ImGui::GetIO();
    io.BackendPlatformUserData = nullptr;
    ImGui::DestroyContext();
}

void GdImGui::Impl_BeginFrame() {
    Impl_NewFrame();
    ImGui::NewFrame();
    static bool yes = true;
    ImGui::ShowDemoWindow(&yes);
}

void GdImGui::Impl_EndFrame() {
    ImGui::Render();
    Impl_RenderData(ImGui::GetDrawData());
}

void GdImGui::Impl_RenderData(ImDrawData* p_draw_data) {
    if (imGuiContext == nullptr) {
        return;
    }

    // Avoid rendering when minimized
    if (p_draw_data->DisplaySize.x <= 0.0f || p_draw_data->DisplaySize.y <= 0.0f)
        return;

    auto rs = RenderingServer::get_singleton();

    for (int n = 0; n < p_draw_data->CmdListsCount; n++) {
        const ImDrawList* cmd_list = p_draw_data->CmdLists[n];

        auto cmdBuf = cmd_list->CmdBuffer;
        auto idxBuf = cmd_list->IdxBuffer;
        auto vtxBuf = cmd_list->VtxBuffer;

        indices.resize(idxBuf.size());
        vertices.resize(vtxBuf.size());
        colors.resize(vtxBuf.size());
        uvs.resize(vtxBuf.size());

        for (int i = 0; i < idxBuf.size(); ++i) {
            indices[i] = idxBuf[i];
        }

        for (int i = 0; i < vtxBuf.size(); ++i) {
            auto& v = vtxBuf[i];
            vertices[i] = {v.pos.x, v.pos.y};
            colors[i] = {
                ((v.col >> 0) & 0xFF) / 255.0f,
                ((v.col >> 8) & 0xFF) / 255.0f,
                ((v.col >> 16) & 0xFF) / 255.0f,
                ((v.col >> 24) & 0xFF) / 255.0f};
            uvs[i] = {v.uv.x, v.uv.y};
        }

        ImVec2 clip_off = p_draw_data->DisplayPos;
        for (int cmd_i = 0; cmd_i < cmdBuf.Size; cmd_i++) {
            const ImDrawCmd* pcmd = &(cmdBuf[cmd_i]);
            if (pcmd->UserCallback) {
                if (pcmd->UserCallback == ImDrawCallback_ResetRenderState) {
                    // reset render state here
                    // ImGui_ImplAllegro5_SetupRenderState(draw_data);
                } else {
                    pcmd->UserCallback(cmd_list, pcmd);
                }
            } else {
                // Project scissor/clipping rectangles into framebuffer space
                Vector2 clip_min(pcmd->ClipRect.x - clip_off.x,
                                 pcmd->ClipRect.y - clip_off.y);
                Vector2 clip_max(pcmd->ClipRect.z - clip_off.x,
                                 pcmd->ClipRect.w - clip_off.y);
                if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y)
                    continue;

                Control* node = get_next_child();
                auto mat = ((ShaderMaterial*)(node->get_material().ptr()));
                mat->set_shader_parameter("scissor_test", Vector4(clip_min.x, clip_min.y, clip_max.x, clip_max.y));

                RID selfRid = node->get_canvas_item();

                auto indicesSlice = indices.slice(pcmd->IdxOffset, pcmd->IdxOffset + pcmd->ElemCount);

                RID texRid;
                Texture2D* tex = (Texture2D*)(pcmd->GetTexID());
                if (tex) {
                    texRid = tex->get_rid();
                    mat->set_shader_parameter("TEXTURE", tex);
                }

                rs->canvas_item_add_triangle_array(selfRid, indicesSlice, vertices, colors, uvs, {}, {}, texRid);
            }
        }
    }
}
