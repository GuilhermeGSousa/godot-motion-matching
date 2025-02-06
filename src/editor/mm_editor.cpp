#include "editor/mm_editor.h"

#include "mm_animation_library.h"
#include "mm_character.h"
#include "mm_editor.h"

#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/h_split_container.hpp>
#include <godot_cpp/classes/resource_saver.hpp>

void MMEditor::_bind_methods() {
    ADD_SIGNAL(MethodInfo("animation_visualization_requested", PropertyInfo(Variant::STRING, "animation_lib_name"), PropertyInfo(Variant::STRING, "animation_name"), PropertyInfo(Variant::INT, "pose_index")));
}

void MMEditor::_notification(int p_notification) {
    switch (p_notification) {
    case NOTIFICATION_ENTER_TREE: {
        HSplitContainer* main_container = memnew(HSplitContainer);
        main_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        add_child(main_container);

        VBoxContainer* left_vbox = memnew(VBoxContainer);
        left_vbox->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        left_vbox->set_h_size_flags(Control::SIZE_EXPAND_FILL);

        _library_selector = memnew(OptionButton);
        _library_selector->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _library_selector->connect("item_selected", callable_mp(this, &MMEditor::_anim_lib_selected));
        left_vbox->add_child(_library_selector);

        _bake_button = memnew(Button);
        _bake_button->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _bake_button->connect("pressed", callable_mp(this, &MMEditor::_bake_button_pressed));
        _bake_button->set_text("Bake");
        // Make a bake all button

        left_vbox->add_child(_bake_button);
        main_container->add_child(left_vbox);

        TabContainer* tab_container = memnew(TabContainer);
        tab_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        tab_container->set_h_size_flags(Control::SIZE_EXPAND_FILL);

        _visualization_tab = memnew(MMVisualizationTab);
        _visualization_tab->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _visualization_tab->connect("animation_visualization_requested", callable_mp(this, &MMEditor::_emit_animation_viz_request));
        tab_container->add_child(_visualization_tab);

        _data_tab = memnew(MMDataTab);
        _data_tab->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        tab_container->add_child(_data_tab);

        main_container->add_child(tab_container);
    } break;
    }
}

void MMEditor::_bake_all_animation_libraries(const AnimationMixer* p_mixer, const Skeleton3D* p_skeleton) {

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

void MMEditor::_refresh(bool character_changed) {
    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();

    if (!animation_mixer) {
        return;
    }

    TypedArray<StringName> animation_library_list = animation_mixer->get_animation_library_list();
    _library_selector->clear();
    for (int64_t i = 0; i < animation_library_list.size(); i++) {
        Ref<MMAnimationLibrary> anim_lib = animation_mixer->get_animation_library(animation_library_list[i]);

        if (anim_lib.is_null()) {
            continue;
        }

        _library_selector->add_item(animation_library_list[i]);
    }
    if (animation_library_list.is_empty()) {
        _library_selector->select(-1);
    } else if (character_changed) {
        _library_selector->select(0);
    }

    _visualization_tab->clear();
    _data_tab->clear();

    const int32_t selected_index = _library_selector->get_selected();
    if (selected_index != -1) {
        _anim_lib_selected(selected_index);
    }
}

void MMEditor::_bake_button_pressed() {
    if (!_current_controller) {
        return;
    }

    Skeleton3D* skeleton = _current_controller->get_skeleton();

    if (!skeleton) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();

    if (!animation_mixer) {
        return;
    }

    String selected_lib = _library_selector->get_text();
    if (selected_lib.is_empty()) {
        return;
    }

    Ref<MMAnimationLibrary> mm_lib = animation_mixer->get_animation_library(selected_lib); //

    if (mm_lib.is_null()) {
        return;
    }

    mm_lib->bake_data(animation_mixer, skeleton);
    ResourceSaver::get_singleton()->save(mm_lib);

    _visualization_tab->refresh();
    _data_tab->set_animation_library(mm_lib);
}

void MMEditor::_anim_lib_selected(int p_index) {
    if (p_index == -1) {
        return;
    }

    if (!_current_controller) {
        return;
    }

    AnimationMixer* animation_mixer = _current_controller->get_animation_mixer();

    if (!animation_mixer) {
        return;
    }

    // We only want the animation libraries that are MMAnimationLibrary
    TypedArray<StringName> mm_animation_library_list;
    PackedStringArray animation_library_list = animation_mixer->get_animation_library_list();
    for (int i = 0; i < animation_library_list.size(); i++) {
        Ref<MMAnimationLibrary> anim_lib = animation_mixer->get_animation_library(animation_library_list[i]);

        if (anim_lib.is_null()) {
            continue;
        }

        mm_animation_library_list.push_back(animation_library_list[i]);
    }

    if (p_index >= mm_animation_library_list.size()) {
        return;
    }

    String animation_lib_name = mm_animation_library_list[p_index];
    Ref<MMAnimationLibrary> anim_lib = animation_mixer->get_animation_library(animation_lib_name);
    if (anim_lib.is_null()) {
        return;
    }

    _visualization_tab->set_animation_library(anim_lib);
    _data_tab->set_animation_library(anim_lib);
}

void MMEditor::_emit_animation_viz_request(String p_animation_lib, String p_animation_name, int32_t p_pose_index) {
    emit_signal("animation_visualization_requested", p_animation_lib, p_animation_name, p_pose_index);
    _current_controller->update_gizmos();
}
