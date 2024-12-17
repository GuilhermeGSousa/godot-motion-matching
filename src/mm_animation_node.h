#ifndef MM_ANIMATION_NODE_H
#define MM_ANIMATION_NODE_H

#include "common.h"
#include "mm_animation_library.h"

#include <godot_cpp/classes/animation_node_extension.hpp>

#include <queue>

class MMAnimationNode : public AnimationNodeExtension {
    GDCLASS(MMAnimationNode, AnimationNodeExtension);

public:
    GETSET(StringName, library);
    GETSET(real_t, query_frequency, 2.0f)
    GETSET(real_t, transition_halflife, 0.1f)

    bool blending_enabled{true};
    bool get_blending_enabled() const;

    void set_blending_enabled(bool value);

    virtual PackedFloat32Array _process_animation_node(const PackedFloat64Array& p_playback_info, bool p_test_only);
    virtual Array _get_parameter_list() const override;
    virtual Variant _get_parameter_default_value(const StringName& p_parameter) const override;
    virtual bool _is_parameter_read_only(const StringName& p_parameter) const override;
    virtual String _get_caption() const override;
    virtual bool _has_filter() const override;

protected:
    void _validate_property(PropertyInfo& p_property) const;
    static void _bind_methods();

private:
    static Dictionary _output_to_dict(const MMQueryOutput& output);

    struct AnimationInfo {
        StringName name;
        double length;
        double time;
        double delta;
        bool seeked;
        bool is_external_seeking;
        real_t weight;
        real_t blend_spring_speed;
    };

    std::deque<AnimationInfo> _prev_animation_queue;
    AnimationInfo _current_animation_info;

    void _start_transition(const StringName p_animation, float p_time);
    PackedFloat32Array _update_current_animation(bool p_test_only);

    MMQueryOutput _last_query_output;
    float _time_since_last_query{0.f};
};

#endif // MM_ANIMATION_NODE_H
