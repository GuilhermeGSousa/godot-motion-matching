#include "editor/mm_editor_plugin.h"

#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/editor_selection.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "mm_editor_plugin.h"

MMEditorPlugin::MMEditorPlugin() {
}

void MMEditorPlugin::_input(const Ref<InputEvent>& p_event) {
    if (p_event->is_class("InputEventMouseButton") && p_event->is_released()) {
        TypedArray<Node> selected_nodes = get_editor_interface()->get_selection()->get_selected_nodes();

        _current_controller = nullptr;
        for (int i = 0; i < selected_nodes.size(); i++) {
            MMCharacter* animation_player = Object::cast_to<MMCharacter>(selected_nodes[i]);

            if (animation_player) {
                _current_controller = animation_player;
                _editor->set_animation_player(_current_controller);
                break;
            }
        }

        _bottom_pannel_button->show();
        _update_visibility();
    }
}

void MMEditorPlugin::_notification(int p_what) {

    switch (p_what) {
    case NOTIFICATION_ENTER_TREE: {
        _editor = memnew(MMEditor);
        _bottom_pannel_button = add_control_to_bottom_panel(_editor, "MMEditor");
        make_bottom_panel_item_visible(_bottom_pannel_button);
        _update_visibility();
        _gizmo_plugin.instantiate();
        _editor->connect("animation_visualization_requested", Callable(_gizmo_plugin.ptr(), "on_anim_viz_requested"));
        add_node_3d_gizmo_plugin(_gizmo_plugin);
    } break;

    case NOTIFICATION_EXIT_TREE: {
        remove_node_3d_gizmo_plugin(_gizmo_plugin);
    } break;
    };
}

void MMEditorPlugin::_update_visibility() {
    if (_current_controller) {
        _bottom_pannel_button->show();
    } else {
        _bottom_pannel_button->hide();
    }
}

void MMEditorPlugin::_bind_methods() {
}
