#ifndef MM_EDITOR_PLUGIN_H
#define MM_EDITOR_PLUGIN_H

#include "animation_post_import_plugin.h"
#include "mm_character.h"
#include "mm_editor.h"
#include "mm_editor_gizmo_plugin.h"

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class MMEditorPlugin : public EditorPlugin {
    GDCLASS(MMEditorPlugin, EditorPlugin)

public:
    MMEditorPlugin();
    ~MMEditorPlugin();

    virtual void _make_visible(bool p_visible) override;
    virtual bool _handles(Object* p_node) const override;
    virtual void _edit(Object* p_object) override;

private:
    static void _bind_methods() {};

    Ref<MMEditorGizmoPlugin> _gizmo_plugin;
    Ref<AnimationPostImportPlugin> _post_import_plugin;

    MMEditor* _editor;
    Button* _bottom_panel_button;
    MMCharacter* _current_controller;
};

#endif // MM_EDITOR_PLUGIN_H
