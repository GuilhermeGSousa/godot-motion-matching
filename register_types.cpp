/**************************************************************************/
/*  register_types.cpp                                                    */
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

#include "register_types.h"

#include "mm_character.h"

#ifdef TOOLS_ENABLED
#include "editor/mm_editor.h"
#include "editor/mm_editor_gizmo_plugin.h"
#include "editor/mm_editor_plugin.h"
#endif

#include "features/mm_bone_data_feature.h"
#include "features/mm_feature.h"
#include "features/mm_trajectory_feature.h"

#include "modifiers/damped_skeleton_modifier.h"

#include "synchronizers/mm_clamp_synchronizer.h"
#include "synchronizers/mm_rootmotion_synchronizer.h"
#include "synchronizers/mm_synchronizer.h"

#include "mm_animation_library.h"
#include "mm_animation_node.h"
#include "mm_query.h"
#include "mm_trajectory_point.h"

void initialize_motion_matching_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_abstract_class<MMFeature>();
        ClassDB::register_class<MMTrajectoryFeature>();
        ClassDB::register_class<MMBoneDataFeature>();

        ClassDB::register_class<MMAnimationLibrary>();
        ClassDB::register_class<MMAnimationNode>();
        ClassDB::register_class<MMQueryInput>();

        ClassDB::register_class<MMCharacter>();

        ClassDB::register_class<DampedSkeletonModifier>();
        ClassDB::register_abstract_class<MMSynchronizer>();
        ClassDB::register_class<MMClampSynchronizer>();
        ClassDB::register_class<MMRootMotionSynchronizer>();
    }
#ifdef TOOLS_ENABLED
    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        EditorPlugins::add_by_type<MMEditorPlugin>();
    }
#endif
}

void uninitialize_motion_matching_module(ModuleInitializationLevel p_level) {
}
