#include "mm_animation_node.h"

#include "mm_query.h"

#include "godot_cpp/classes/ref.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

double MMAnimationNode::_process(double p_time, bool p_seek, bool p_is_external_seeking, bool p_test_only) {
    // Get the motion matching query input
    // Variant input = get_parameter(motion_matching_input);
    return 0.0;
}

Array MMAnimationNode::_get_parameter_list() const {
    Array param_list;
    param_list.push_back(Dictionary(
        PropertyInfo(Variant::Type::OBJECT, motion_matching_input)));
    return param_list;
}

Variant MMAnimationNode::_get_parameter_default_value(const StringName& p_parameter) const {
    if (p_parameter == motion_matching_input) {
        Ref<MMQueryInputRefCounted> input;
        input.instantiate();
        return input;
    }
    return Variant();
}

String MMAnimationNode::_get_caption() const {
    return "Motion Matching";
}

void MMAnimationNode::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::OBJECT, animation_library, PROPERTY_HINT_RESOURCE_TYPE, "MMAnimationLibrary");
}
