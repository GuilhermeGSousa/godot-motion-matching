#include "mm_data_tab.h"

#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/scroll_container.hpp>
#include <godot_cpp/classes/v_box_container.hpp>

void MMDataTab::set_animation_library(Ref<MMAnimationLibrary> p_library) {
    if (p_library.is_null()) {
        return;
    }

    _clear_data();

    Label* min_label = memnew(Label);
    min_label->set_text("Min");
    _stats_data_container->add_child(min_label);

    Label* max_label = memnew(Label);
    max_label->set_text("Max");
    _stats_data_container->add_child(max_label);

    Label* avg_label = memnew(Label);
    avg_label->set_text("Avg");
    _stats_data_container->add_child(avg_label);

    Label* std_label = memnew(Label);
    std_label->set_text("Std");
    _stats_data_container->add_child(std_label);

    TypedArray<MMFeature> features = p_library->get_features();
    for (int i = 0; i < features.size(); i++) {

        Ref<MMFeature> feature = features[i];
        if (feature.is_null()) {
            return;
        }

        for (int i = 0; i < feature->get_dimension_count(); i++) {
            Label* min_value = memnew(Label);
            min_value->set_text(String::num(feature->get_mins()[i]));
            _stats_data_container->add_child(min_value);

            Label* max_value = memnew(Label);
            max_value->set_text(String::num(feature->get_maxes()[i]));
            _stats_data_container->add_child(max_value);

            Label* avg_value = memnew(Label);
            avg_value->set_text(String::num(feature->get_means()[i]));
            _stats_data_container->add_child(avg_value);

            Label* std_value = memnew(Label);
            std_value->set_text(String::num(feature->get_std_devs()[i]));
            _stats_data_container->add_child(std_value);
        }

        // Label* feature_label = memnew(Label);
        // feature_label->set_text(features[i].name);
        // _stats_data_container->add_child(feature_label);

        // Label* min_value = memnew(Label);
        // min_value->set_text(String::num(features[i].min));
        // _stats_data_container->add_child(min_value);

        // Label* max_value = memnew(Label);
        // max_value->set_text(String::num(features[i].max));
        // _stats_data_container->add_child(max_value);

        // Label* avg_value = memnew(Label);
        // avg_value->set_text(String::num(features[i].avg));
        // _stats_data_container->add_child(avg_value);

        // Label* std_value = memnew(Label);
        // std_value->set_text(String::num(features[i].std));
        // _stats_data_container->add_child(std_value);
    }
}

void MMDataTab::clear() {
    _clear_data();
}

void MMDataTab::_bind_methods() {
}

void MMDataTab::_notification(int p_notification) {
    switch (p_notification) {
    case NOTIFICATION_ENTER_TREE: {
        set_name("Data");

        ScrollContainer* scroll_container = memnew(ScrollContainer);
        scroll_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        add_child(scroll_container);

        VBoxContainer* main_container = memnew(VBoxContainer);
        scroll_container->add_child(main_container);

        _stats_data_container = memnew(GridContainer);
        _stats_data_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        _stats_data_container->set_columns(4); // min, max, avg, std
        main_container->add_child(_stats_data_container);

        _motion_data_container = memnew(GridContainer);
        _motion_data_container->set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
        main_container->add_child(_motion_data_container);

    } break;
    }
}

void MMDataTab::_clear_data() {
    TypedArray<Node> stat_cells = _stats_data_container->get_children();
    for (int i = 0; i < stat_cells.size(); i++) {
        Node* cell = Object::cast_to<Node>(stat_cells[i]);
        cell->queue_free();
    }
}
