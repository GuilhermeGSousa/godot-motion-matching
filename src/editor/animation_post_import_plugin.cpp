#include "animation_post_import_plugin.h"

#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/file_access.hpp"
#include "godot_cpp/classes/node.hpp"

Variant AnimationPostImportPlugin::_get_option_visibility(const String& p_path, bool p_for_animation, const String& p_option) const {
    if (p_option == "export/animation_export_path") {
        return p_for_animation;
    }
    return EditorScenePostImportPlugin::_get_option_visibility(p_path, p_for_animation, p_option);
}

void AnimationPostImportPlugin::_get_import_options(const String& p_path) {
    add_import_option_advanced(Variant::STRING, "export/animation_export_path", "", PROPERTY_HINT_DIR, "");
}

void AnimationPostImportPlugin::_pre_process(Node* p_scene) {

    const String export_path = get_option_value("export/animation_export_path");

    if (export_path.is_empty()) {
        return;
    }

    Dictionary animations;
    _export_animations(p_scene, animations, export_path);

    Dictionary subresources = get_option_value("_subresources");
    subresources["animations"] = animations;
}

void AnimationPostImportPlugin::_bind_methods() {
}

void AnimationPostImportPlugin::_export_animations(Node* p_node, Dictionary& p_animations, const String& p_export_path) {
    AnimationPlayer* anim_node = Object::cast_to<AnimationPlayer>(p_node);

    if (anim_node) {
        PackedStringArray anim_list = anim_node->get_animation_list();

        for (int32_t i = 0; i < anim_list.size(); i++) {
            StringName anim_name = anim_list[i];

            Dictionary animation;
            animation["save_to_file/enabled"] = true;
            animation["save_to_file/keep_custom_tracks"] = "";

            String clean_anim_name = anim_name.validate_filename();
            String file_path = p_export_path.path_join(clean_anim_name) + ".res";
            int idx = 1;
            while (FileAccess::file_exists(file_path)) {
                file_path = p_export_path.path_join(clean_anim_name + String::num_int64(idx)) + ".res";
                idx++;
            }

            animation["save_to_file/path"] = file_path;

            p_animations[anim_name] = animation;
        }
    }

    for (int32_t i = 0; i < p_node->get_child_count(); i++) {
        _export_animations(p_node->get_child(i), p_animations, p_export_path);
    }
}
