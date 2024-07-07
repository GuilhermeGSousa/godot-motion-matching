#pragma once

#include <chrono>

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/shader.hpp>
#include <godot_cpp/classes/shader_material.hpp>
#include <godot_cpp/classes/texture2d.hpp>

#include <imgui.h>

using namespace godot;

class GdImGui : public Node2D {
    GDCLASS(GdImGui, Node2D)
public:
    virtual void _enter_tree();
    virtual void _exit_tree();
    virtual void _ready();
    virtual void _process(double delta);

protected:
    static void _bind_methods();

private:
    Control* get_next_child();

    void Impl_NewFrame();
    void Impl_Init();
    void Impl_InitFonts();
    void Impl_Shutdown();
    void Impl_BeginFrame();
    void Impl_EndFrame();
    void Impl_RenderData(ImDrawData* p_draw_data);

    ImGuiContext* imGuiContext = nullptr;
    Ref<Texture2D> font_texture;
    Ref<Shader> shader;
    Ref<ShaderMaterial> material;

    PackedInt32Array indices;
    PackedVector2Array vertices;
    PackedColorArray colors;
    PackedVector2Array uvs;
    int nextFreeChild = 0;

    bool show_demo_window = true;

    std::chrono::steady_clock::time_point prev_frame_start = std::chrono::steady_clock::now();
};