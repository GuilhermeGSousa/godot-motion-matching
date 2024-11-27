#include "register_types.h"

#include <gdextension_interface.h>

#include "mm_character.h"

#include "editor/animation_tree_handler_plugin.h"
#include "editor/mm_editor.h"
#include "editor/mm_editor_gizmo_plugin.h"
#include "editor/mm_editor_plugin.h"

#include "features/mm_bone_data_feature.h"
#include "features/mm_feature.h"
#include "features/mm_trajectory_feature.h"

#include "modifiers/damped_skeleton_modifier.h"

#include "synchronizers/mm_clamp_synchronizer.h"
#include "synchronizers/mm_mix_synchronizer.h"
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
        ClassDB::register_class<MMMixSynchronizer>();
    }

    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        ClassDB::register_internal_class<AnimationTreeHandlerPlugin>();
        ClassDB::register_internal_class<MMEditorGizmoPlugin>();
        ClassDB::register_internal_class<MMEditor>();
        ClassDB::register_internal_class<MMEditorPlugin>();

        EditorPlugins::add_by_type<MMEditorPlugin>();
        EditorPlugins::add_by_type<AnimationTreeHandlerPlugin>();
    }
}

void uninitialize_motion_matching_module(ModuleInitializationLevel p_level) {
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_motion_matching_module);
    init_obj.register_terminator(uninitialize_motion_matching_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SERVERS);

    return init_obj.init();
}
}
