/**************************************************************************/
/*  mm_editor_gizmo_plugin.cpp                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "editor/plugins/node_3d_editor_gizmos.h"
#include "modules/motion_matching/src/mm_animation_library.h"
#include "modules/motion_matching/src/mm_character.h"
#include "scene/animation/animation_mixer.h"

#include "mm_character.h"
#include "mm_editor_gizmo_plugin.h"

MMEditorGizmoPlugin::MMEditorGizmoPlugin() {
}

bool MMEditorGizmoPlugin::has_gizmo(Node3D* p_for_node_3d) {
    return p_for_node_3d->is_class("MMCharacter");
}

String MMEditorGizmoPlugin::get_gizmo_name() const {
    return "MMEditorGizmo";
}

void MMEditorGizmoPlugin::redraw(EditorNode3DGizmo* p_gizmo) {
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
