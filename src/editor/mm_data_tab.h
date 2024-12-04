#pragma once

#include "mm_animation_library.h"

#include <godot_cpp/classes/grid_container.hpp>
#include <godot_cpp/classes/option_button.hpp>
#include <godot_cpp/classes/tab_bar.hpp>

using namespace godot;

class MMDataTab : public TabBar {
    GDCLASS(MMDataTab, TabBar)

public:
    void set_animation_library(Ref<MMAnimationLibrary> p_library);
    void clear();

protected:
    static void _bind_methods();
    void _notification(int p_notification);

private:
    void _clear_data();

    // Data
    GridContainer* _motion_data_container;
    GridContainer* _stats_data_container;
};