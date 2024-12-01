#pragma once

#include "mm_animation_library.h"

#include <godot_cpp/classes/grid_container.hpp>
#include <godot_cpp/classes/h_slider.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/option_button.hpp>
#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/classes/v_box_container.hpp>

using namespace godot;

class MMVisualizationTab : public TabBar {
    GDCLASS(MMVisualizationTab, TabBar)

public:
    void set_animation_library(Ref<MMAnimationLibrary> p_library) {
        _current_animation_library = p_library;
        refresh();
    }

    void set_enabled(bool p_enabled);
    void refresh();
    void clear();

protected:
    static void _bind_methods();
    void _notification(int p_notification);

private:
    void _viz_time_changed(float p_value);
    void _viz_anim_selected(int p_index);
    void _emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index);

    Ref<MMAnimationLibrary> _current_animation_library;

    // Visualization
    Label* _warning_label;
    VBoxContainer* _visualization_vbox;
    OptionButton* _viz_animation_option_button;
    HSlider* _viz_time_slider;
    int _selected_animation_index = -1;
};