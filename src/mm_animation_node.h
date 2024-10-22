#pragma once

#include <godot_cpp/classes/animation_root_node.hpp>

#include "common.h"
#include "mm_animation_library.h"

using namespace godot;

class MMAnimationNode : public AnimationRootNode {
    GDCLASS(MMAnimationNode, AnimationRootNode)

public:
    virtual double _process(double p_time, bool p_seek, bool p_is_external_seeking, bool p_test_only) override;
    virtual Array _get_parameter_list() const;
    virtual Variant _get_parameter_default_value(const StringName& p_parameter) const;
    virtual String _get_caption() const;

    GETSET(Ref<MMAnimationLibrary>, animation_library)

protected:
    static void _bind_methods();

private:
    const StringName motion_matching_input = "motion_matching_input";
};