/**************************************************************************/
/*  mm_editor.cpp                                                         */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "mm_editor.h"

#include "editor/editor_interface.h"
#include "mm_animation_library.h"
#include "mm_character.h"
#include "mm_editor.h"

#include "scene/gui/box_container.h"
#include "scene/gui/button.h"
#include "scene/gui/tab_bar.h"
#include "scene/gui/tab_container.h"

MMEditor::MMEditor() {
    TabContainer* tab_container = memnew(TabContainer);
    tab_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);

    add_child(tab_container);

    // Baking tab
    {
        TabBar* baking_tab = memnew(TabBar);
        baking_tab->set_name("Baking");

        Button* bake_button = memnew(Button);
        bake_button->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        bake_button->connect("pressed", Callable(this, "_bake_button_pressed"));
        bake_button->set_text("Bake");

        baking_tab->add_child(bake_button);

        tab_container->add_child(baking_tab);
    }

    // Visualization tab
    {
        TabBar* visualization_tab = memnew(TabBar);
        visualization_tab->set_name("Visualization");

        VBoxContainer* visualization_vbox = memnew(VBoxContainer);
        visualization_vbox->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        visualization_tab->add_child(visualization_vbox);

        _viz_animation_option_button = memnew(OptionButton);
        _viz_animation_option_button->connect("item_selected", Callable(this, "_viz_anim_selected"));
        visualization_vbox->add_child(_viz_animation_option_button);

        _viz_time_slider = memnew(HSlider);
        _viz_time_slider->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _viz_time_slider->set_min(0);
        _viz_time_slider->set_max(1);
        _viz_time_slider->set_step(1);
        _viz_time_slider->connect("value_changed", Callable(this, "_viz_time_changed"));
        visualization_vbox->add_child(_viz_time_slider);

        tab_container->add_child(visualization_tab);
    }
}
void MMEditor::_bind_methods() {
    ADD_SIGNAL(MethodInfo("animation_visualization_requested", PropertyInfo(Variant::STRING, "animation_lib_name"), PropertyInfo(Variant::STRING, "animation_name"), PropertyInfo(Variant::INT, "pose_index")));

    ClassDB::bind_method(D_METHOD("_bake_button_pressed"), &MMEditor::_bake_button_pressed);
    ClassDB::bind_method(D_METHOD("_viz_anim_selected", "p_index"), &MMEditor::_viz_anim_selected);
    ClassDB::bind_method(D_METHOD("_viz_time_changed", "p_value"), &MMEditor::_viz_time_changed);
}

void MMEditor::_bake_animation_libraries(const AnimationMixer* p_mixer, const Skeleton3D* p_skeleton) {

    List<StringName> animation_libraries;
    p_mixer->get_animation_library_list(&animation_libraries);

    for (int i = 0; i < animation_libraries.size(); i++) {
        const StringName& anim_lib_name = animation_libraries.get(i);
        Ref<MMAnimationLibrary> anim_lib = p_mixer->get_animation_library(anim_lib_name);

        if (anim_lib.is_null()) {
            continue;
        }

        anim_lib->bake_data(p_mixer, p_skeleton);
    }
}

void MMEditor::_refresh() {
    _selected_animation_index = -1;
    _current_animation_library_name = "";
    _current_animation_name = "";

    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_player = _current_controller->get_animation_mixer();

    if (!animation_player) {
        return;
    }
    List<StringName> animations;
    animation_player->get_animation_list(&animations);
    _viz_animation_option_button->clear();
    for (int i = 0; i < animations.size(); i++) {
        String animation_name = animations.get(i);
        _viz_animation_option_button->add_item(animation_name, i);
    }
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
    List<StringName> animations_list;
    animation_mixer->get_animation_list(&animations_list);
    String animation_name = animations_list.get(p_index);

    PackedStringArray split_anim_name = animation_name.split("/");
    String anim_lib_name = split_anim_name[0];
    String anim_name = split_anim_name[1];
    print_line("Selected animation: " + anim_lib_name);
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
