
#include "editor/mm_editor_plugin.h"

#include <godot_cpp/variant/utility_functions.hpp>

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/classes/tab_container.hpp>
#include <godot_cpp/classes/v_box_container.hpp>

MMEditorPlugin::MMEditorPlugin() {
    _editor = memnew(MMEditor);
    _gizmo_plugin.instantiate();
    add_node_3d_gizmo_plugin(_gizmo_plugin);
    _bottom_panel_button = add_control_to_bottom_panel(_editor, "MMEditor");
    _editor->connect("animation_visualization_requested", callable_mp(_gizmo_plugin.ptr(), &MMEditorGizmoPlugin::on_anim_viz_requested));
}

MMEditorPlugin::~MMEditorPlugin() {
    remove_control_from_bottom_panel(_bottom_panel_button);
    remove_node_3d_gizmo_plugin(_gizmo_plugin);
    remove_control_from_bottom_panel(_editor);
    if (_editor) {
        memdelete(_editor);
        _editor = nullptr;
    }
    if (_gizmo_plugin.is_valid()) {
        _gizmo_plugin.unref();
    }
}

void MMEditorPlugin::_make_visible(bool p_visible) {
    if (p_visible) {
        _bottom_panel_button->show();
    } else {
        _bottom_panel_button->hide();
        hide_bottom_panel();
    }
}

bool MMEditorPlugin::_handles(Object* p_node) const {
    return (Object::cast_to<MMCharacter>(p_node) != nullptr);
}

void MMEditorPlugin::_edit(Object* p_object) {
    MMCharacter* character = Object::cast_to<MMCharacter>(p_object);
    _make_visible(character != nullptr);

    if (!character) {
        return;
    }

    _editor->set_character(character);
}
