#ifndef MM_EDITOR_H
#define MM_EDITOR_H

#include <godot_cpp/classes/animation_mixer.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/h_slider.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/option_button.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/classes/tab_container.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class MMAnimationLibrary;
class MMCharacter;

class MMEditor : public Control {
    GDCLASS(MMEditor, Control)

public:
    MMEditor();
    virtual ~MMEditor();
    void set_character(MMCharacter* p_controller) {
        const bool changed = p_controller != _current_controller;

        _current_controller = p_controller;
        if (changed) {
            _refresh();
        }
    }

    void set_visualization_enabled(bool p_enabled);

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
    TabContainer* _tab_container;

    // Visualization
    Label* _warning_label;
    TabBar* _visualization_tab;
    VBoxContainer* _visualization_vbox;
    OptionButton* _viz_animation_option_button;
    HSlider* _viz_time_slider;

    // Baking
    TabBar* _baking_tab;
    Button* _bake_button;

    int _selected_animation_index = -1;
};
#endif // MM_EDITOR_H
