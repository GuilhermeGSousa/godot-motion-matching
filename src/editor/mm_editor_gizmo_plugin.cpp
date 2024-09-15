#include "editor/mm_editor_gizmo_plugin.h"

#include <godot_cpp/classes/animation_mixer.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "mm_animation_library.h"
#include "mm_character.h"
#include "mm_editor_gizmo_plugin.h"

MMEditorGizmoPlugin::MMEditorGizmoPlugin() {
}

bool MMEditorGizmoPlugin::_has_gizmo(Node3D* p_for_node_3d) const {
    return p_for_node_3d->is_class("MMCharacter");
}

String MMEditorGizmoPlugin::_get_gizmo_name() const {
    return "MMEditorGizmo";
}

void MMEditorGizmoPlugin::_redraw(const Ref<EditorNode3DGizmo>& p_gizmo) {
    p_gizmo->clear();

    MMCharacter* controller = Object::cast_to<MMCharacter>(p_gizmo->get_node_3d());
    if (!controller) {
        return;
    }

    AnimationMixer* animation_mixer = controller->get_animation_mixer();
    if (!animation_mixer) {
        return;
    }

    if (!animation_mixer->has_animation_library(_animation_lib)) {
        return;
    }

    Ref<MMAnimationLibrary> animation_library = animation_mixer->get_animation_library(_animation_lib);
    if (animation_library.is_null()) {
        return;
    }

    animation_library->display_data(
        p_gizmo,
        controller->get_global_transform(),
        _animation_name,
        _pose_index);
}

void MMEditorGizmoPlugin::on_anim_viz_requested(String p_animation_lib, String p_animation_name, int32_t p_pose_index) {
    _animation_lib = p_animation_lib;
    _animation_name = p_animation_name;
    _pose_index = p_pose_index;
}
void MMEditorGizmoPlugin::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_anim_viz_requested", "animation_lib", "animation_name", "pose_index"), &MMEditorGizmoPlugin::on_anim_viz_requested);
}
