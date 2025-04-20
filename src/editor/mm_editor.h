#pragma once

#include "mm_data_tab.h"
#include "mm_visualization_tab.h"

#include <godot_cpp/classes/animation_mixer.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/tab_container.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class MMAnimationLibrary;
class MMCharacter;

class MMEditor : public Control {
    GDCLASS(MMEditor, Control)

public:
    void set_character(MMCharacter* p_controller) {
        const bool changed = p_controller != _current_controller;

        _current_controller = p_controller;
        _refresh(changed);
    }

protected:
    static void _bind_methods();
    void _notification(int p_notification);

private:
    static void _bake_all_animation_libraries(const MMCharacter* p_character, const AnimationMixer* p_mixer, const Skeleton3D* p_skeleton);
    void _refresh(bool character_changed);
    void _bake_button_pressed();
    void _anim_lib_selected(int p_index);

    void _emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index);

    MMCharacter* _current_controller;
    String _current_animation_library_name;
    String _current_animation_name;

    OptionButton* _library_selector;
    Button* _bake_button;

    MMVisualizationTab* _visualization_tab;
    MMDataTab* _data_tab;
};
