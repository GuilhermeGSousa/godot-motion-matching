#include "editor/mm_editor.h"

#include "mm_animation_library.h"
#include "mm_character.h"
#include "mm_editor.h"

#include <godot_cpp/classes/resource_saver.hpp>

MMEditor::MMEditor() {
    _tab_container = memnew(TabContainer);
    _tab_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);

    add_child(_tab_container);

    // Baking tab
    {
        _baking_tab = memnew(TabBar);
        _baking_tab->set_name("Baking");

        _bake_button = memnew(Button);
        _bake_button->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _bake_button->connect("pressed", Callable(this, "_bake_button_pressed"));
        _bake_button->set_text("Bake");

        _baking_tab->add_child(_bake_button);

        _tab_container->add_child(_baking_tab);
    }

    // Visualization tab
    {
        _visualization_tab = memnew(TabBar);
        _visualization_tab->set_name("Visualization");

        _visualization_vbox = memnew(VBoxContainer);
        _visualization_vbox->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _visualization_tab->add_child(_visualization_vbox);

        _warning_label = memnew(Label);
        _warning_label->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _warning_label->set_text("No character selected");
        _visualization_vbox->add_child(_warning_label);

        _viz_animation_option_button = memnew(OptionButton);
        _viz_animation_option_button->connect("item_selected", Callable(this, "_viz_anim_selected"));
        _visualization_vbox->add_child(_viz_animation_option_button);

        _viz_time_slider = memnew(HSlider);
        _viz_time_slider->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _viz_time_slider->set_min(0);
        _viz_time_slider->set_max(1);
        _viz_time_slider->set_step(1);
        _viz_time_slider->connect("value_changed", Callable(this, "_viz_time_changed"));
        _visualization_vbox->add_child(_viz_time_slider);

        _tab_container->add_child(_visualization_tab);
    }

    set_visualization_enabled(false);
}

MMEditor::~MMEditor() {
    memdelete(_tab_container);
}

void MMEditor::set_visualization_enabled(bool p_enabled) {
    if (p_enabled) {
        _warning_label->hide();
    } else {
        _warning_label->show();
        _warning_label->set_text("Library data is out of date. Bake data to enable visualization.");
    }
    _viz_animation_option_button->set_disabled(!p_enabled);
    _viz_time_slider->set_editable(p_enabled);
}

void MMEditor::_bind_methods() {
    ADD_SIGNAL(MethodInfo("animation_visualization_requested", PropertyInfo(Variant::STRING, "animation_lib_name"), PropertyInfo(Variant::STRING, "animation_name"), PropertyInfo(Variant::INT, "pose_index")));

    ClassDB::bind_method(D_METHOD("_bake_button_pressed"), &MMEditor::_bake_button_pressed);
    ClassDB::bind_method(D_METHOD("_viz_anim_selected", "p_index"), &MMEditor::_viz_anim_selected);
    ClassDB::bind_method(D_METHOD("_viz_time_changed", "p_value"), &MMEditor::_viz_time_changed);
}

void MMEditor::_bake_animation_libraries(const AnimationMixer* p_mixer, const Skeleton3D* p_skeleton) {

    TypedArray<StringName> animation_libraries = p_mixer->get_animation_library_list();
    for (int i = 0; i < animation_libraries.size(); i++) {
        const StringName& anim_lib_name = animation_libraries[i];
        Ref<MMAnimationLibrary> anim_lib = p_mixer->get_animation_library(anim_lib_name);

        if (anim_lib.is_null()) {
            continue;
        }

        anim_lib->bake_data(p_mixer, p_skeleton);
        ResourceSaver::get_singleton()->save(anim_lib);
    }
}

void MMEditor::_refresh() {
    _selected_animation_index = -1;
    _current_animation_library_name = "";
    _current_animation_name = "";

    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();

    if (!animation_mixer) {
        return;
    }

    PackedStringArray animations = animation_mixer->get_animation_list();
    _viz_animation_option_button->clear();
    for (int i = 0; i < animations.size(); i++) {
        String animation_name = animations[i];
        _viz_animation_option_button->add_item(animation_name, i);
    }
    _viz_animation_option_button->select(-1);

    bool needs_baking = false;
    TypedArray<StringName> animation_library_list = animation_mixer->get_animation_library_list();
    for (int64_t i = 0; i < animation_library_list.size(); i++) {
        Ref<MMAnimationLibrary> anim_lib = animation_mixer->get_animation_library(animation_library_list[i]);
        if (anim_lib.is_null()) {
            continue;
        }

        if (anim_lib->compute_features_hash() != anim_lib->get_schema_hash()) {
            needs_baking = true;
            break;
        }
    }
    set_visualization_enabled(!needs_baking);
}

void MMEditor::_bake_button_pressed() {
    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();

    if (!animation_mixer) {
        return;
    }

    _bake_animation_libraries(animation_mixer, _current_controller->get_skeleton());
    _refresh();
}

void MMEditor::_viz_anim_selected(int p_index) {
    _selected_animation_index = p_index;

    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();
    if (!animation_mixer) {
        return;
    }

    PackedStringArray animations_list = animation_mixer->get_animation_list();
    String animation_name = animations_list[p_index];

    PackedStringArray split_anim_name = animation_name.split("/");
    String anim_lib_name = split_anim_name[0];
    String anim_name = split_anim_name[1];
    Ref<MMAnimationLibrary> anim_lib = animation_mixer->get_animation_library(anim_lib_name);

    if (anim_lib.is_null()) {
        return;
    }

    _current_animation_library_name = anim_lib_name;
    _current_animation_name = anim_name;

    _viz_time_slider->set_max(anim_lib->get_animation_pose_count(anim_name));
}

void MMEditor::_viz_time_changed(float p_value) {
    if (!_current_controller ||
        _current_animation_library_name.is_empty() ||
        _current_animation_name.is_empty()) {
        return;
    }

    if (_selected_animation_index == -1) {
        return;
    }
    _emit_animation_viz_request(_current_animation_library_name, _current_animation_name, p_value);
    _current_controller->update_gizmos();
}

void MMEditor::_emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index) {
    emit_signal("animation_visualization_requested", p_animation_lib, p_animation_name, p_pose_index);
}
