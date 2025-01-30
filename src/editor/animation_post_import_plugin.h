#pragma once

#include <godot_cpp/classes/editor_scene_post_import_plugin.hpp>

using namespace godot;

class AnimationPostImportPlugin : public EditorScenePostImportPlugin {
    GDCLASS(AnimationPostImportPlugin, EditorScenePostImportPlugin)

public:
    virtual Variant _get_option_visibility(const String& p_path, bool p_for_animation, const String& p_option) const override;

    virtual void _get_import_options(const String& p_path) override;
    virtual void _pre_process(Node* p_scene) override;

protected:
    static void _bind_methods();

private:
    void _export_animations(Node* p_node, Dictionary& p_animations, const String& p_export_path);
};
