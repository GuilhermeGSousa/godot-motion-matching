#include "mm_visualization_tab.h"

void MMVisualizationTab::set_enabled(bool p_enabled) {
    if (p_enabled) {
        _warning_label->hide();
    } else {
        _warning_label->show();
        _warning_label->set_text("Library data is out of date. Bake data to enable visualization.");
    }
    _viz_animation_option_button->set_disabled(!p_enabled);
    _viz_time_slider->set_editable(p_enabled);
}

void MMVisualizationTab::_bind_methods() {
    ADD_SIGNAL(MethodInfo("animation_visualization_requested", PropertyInfo(Variant::STRING, "animation_lib_name"), PropertyInfo(Variant::STRING, "animation_name"), PropertyInfo(Variant::INT, "pose_index")));
}

void MMVisualizationTab::_notification(int p_notification) {
    switch (p_notification) {
    case NOTIFICATION_ENTER_TREE: {
        set_name("Visualization");

        _visualization_vbox = memnew(VBoxContainer);
        _visualization_vbox->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        add_child(_visualization_vbox);

        _warning_label = memnew(Label);
        _warning_label->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _warning_label->set_text("No character selected");
        _visualization_vbox->add_child(_warning_label);

        _viz_animation_option_button = memnew(OptionButton);
        _viz_animation_option_button->connect("item_selected", callable_mp(this, &MMVisualizationTab::_viz_anim_selected));
        _visualization_vbox->add_child(_viz_animation_option_button);

        _viz_time_slider = memnew(HSlider);
        _viz_time_slider->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _viz_time_slider->set_min(0);
        _viz_time_slider->set_max(1);
        _viz_time_slider->set_step(1);
        _viz_time_slider->connect("value_changed", callable_mp(this, &MMVisualizationTab::_viz_time_changed));
        _visualization_vbox->add_child(_viz_time_slider);
    }
    }
}

void MMVisualizationTab::_viz_time_changed(float p_value) {

    if (_selected_animation_index == -1) {
        return;
    }

    if (_current_animation_library.is_null()) {
        return;
    }

    TypedArray<StringName> animation_list = _current_animation_library->get_animation_list();
    StringName animation_name = animation_list[_selected_animation_index];
    String anim_lib_name = _current_animation_library->get_path().get_file().get_basename();

    UtilityFunctions::print(anim_lib_name);
    _emit_animation_viz_request(anim_lib_name, animation_name, p_value);
}

void MMVisualizationTab::_viz_anim_selected(int p_index) {
    _selected_animation_index = p_index;

    if (_current_animation_library.is_null()) {
        return;
    }

    TypedArray<StringName> animation_list = _current_animation_library->get_animation_list();
    StringName animation_name = animation_list[p_index];

    _viz_time_slider->set_max(_current_animation_library->get_animation_pose_count(animation_name));
}

void MMVisualizationTab::_emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index) {
    emit_signal("animation_visualization_requested", p_animation_lib, p_animation_name, p_pose_index);
}

void MMVisualizationTab::refresh() {
    clear();

    if (_current_animation_library.is_null()) {
        return;
    }

    TypedArray<StringName> animations = _current_animation_library->get_animation_list();

    for (int i = 0; i < animations.size(); i++) {
        StringName animation_name = animations[i];
        _viz_animation_option_button->add_item(animation_name, i);
    }

    if (_current_animation_library->needs_baking()) {
    }

    set_enabled(!_current_animation_library->needs_baking());
}

void MMVisualizationTab::clear() {
    _selected_animation_index = -1;
    _viz_animation_option_button->clear();
    _viz_animation_option_button->select(-1);

    set_enabled(false);
}
