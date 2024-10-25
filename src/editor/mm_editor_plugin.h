#pragma once

#include "editor/mm_editor.h"
#include "editor/mm_editor_gizmo_plugin.h"
#include "mm_character.h"
#include "modules/motion_matching/src/editor/mm_editor_gizmo_plugin.h"

#include "scene/gui/button.h"
#include "editor/plugins/editor_plugin.h"
#include "core/input/input_event.h"
#include "core/object/ref_counted.h"

class MMEditorPlugin : public EditorPlugin {
    GDCLASS(MMEditorPlugin, EditorPlugin)

public:
    MMEditorPlugin();

    virtual void input(const Ref<InputEvent>& p_event) override;

private:
    void _notification(int p_what);
    void _update_visibility();

    static void _bind_methods();

    Ref<MMEditorGizmoPlugin> _gizmo_plugin;

    MMEditor* _editor;
    Button* _bottom_pannel_button;
    MMCharacter* _current_controller;
};
