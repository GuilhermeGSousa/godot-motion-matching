#pragma once

#include "scene/animation/animation_mixer.h"
#include "scene/gui/control.h"
#include "scene/gui/slider.h"
#include "scene/gui/option_button.h"
#include "scene/3d/skeleton_3d.h"

class MMAnimationLibrary;
class MMCharacter;

class MMEditor : public Control {
    GDCLASS(MMEditor, Control)

public:
    MMEditor();

    void set_animation_player(MMCharacter* p_controller) {
        const bool changed = p_controller != _current_controller;

        _current_controller = p_controller;
        if (changed) {
            _refresh();
        }
    }

protected:
    static void _bind_methods();

private:
    static void _bake_animation_libraries(const AnimationMixer* p_mixer, const Skeleton3D* p_skeleton);
    void _refresh();
    void _bake_button_pressed();
    void _viz_anim_selected(int p_index);
    void _viz_time_changed(float p_value);
    void _emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index);
    MMCharacter* _current_controller;
    String _current_animation_library_name;
    String _current_animation_name;

    // UI Elements
    OptionButton* _viz_animation_option_button;
    HSlider* _viz_time_slider;

    int _selected_animation_index = -1;
};