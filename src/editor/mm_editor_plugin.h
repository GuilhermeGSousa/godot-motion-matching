#pragma once

#include "editor/mm_editor.h"
#include "editor/mm_editor_gizmo_plugin.h"
#include "mm_controller.h"

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/ref.hpp>

using namespace godot;

class MMEditorPlugin : public EditorPlugin {
    GDCLASS(MMEditorPlugin, EditorPlugin)

public:
    MMEditorPlugin();

    virtual void _input(const Ref<InputEvent>& p_event) override;

private:
    void _notification(int p_what);
    void _update_visibility();

    static void _bind_methods();

    Ref<MMEditorGizmoPlugin> _gizmo_plugin;

    MMEditor* _editor;
    Button* _bottom_pannel_button;
    MMController* _current_controller;
};
