#include "register_types.h"

#include "mm_character.h"

#include "editor/mm_editor.h"
#include "editor/mm_editor_gizmo_plugin.h"
#include "editor/mm_editor_plugin.h"

#include "features/mm_bone_data_feature.h"
#include "features/mm_feature.h"
#include "features/mm_trajectory_feature.h"

#include "modifiers/damped_skeleton_modifier.h"

#include "synchronizers/mm_clamp_synchronizer.h"
#include "synchronizers/mm_rootmotion_synchronizer.h"
#include "synchronizers/mm_synchronizer.h"

#include "mm_animation_library.h"
#include "mm_trajectory_point.h"

void initialize_motion_matching_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        ClassDB::register_internal_class<MMEditorGizmoPlugin>();
        ClassDB::register_internal_class<MMEditor>();
        ClassDB::register_internal_class<MMEditorPlugin>();

        EditorPlugins::add_by_type<MMEditorPlugin>();
    }

    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_abstract_class<MMFeature>();
        ClassDB::register_class<MMTrajectoryFeature>();
        ClassDB::register_class<MMBoneDataFeature>();

        ClassDB::register_class<MMAnimationLibrary>();

        ClassDB::register_class<MMCharacter>();

        ClassDB::register_class<DampedSkeletonModifier>();

        ClassDB::register_abstract_class<MMSynchronizer>();
        ClassDB::register_class<MMClampSynchronizer>();
        ClassDB::register_class<MMRootMotionSynchronizer>();
    }
}

void uninitialize_motion_matching_module(ModuleInitializationLevel p_level) {
}
