/**************************************************************************/
/*  mm_editor.h                                                           */
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

#ifndef MM_EDITOR_H
#define MM_EDITOR_H

#include "scene/3d/skeleton_3d.h"
#include "scene/animation/animation_mixer.h"
#include "scene/gui/control.h"
#include "scene/gui/option_button.h"
#include "scene/gui/slider.h"

class MMAnimationLibrary;
class MMCharacter;

class MMEditor : public Control {
    GDCLASS(MMEditor, Control)

public:
    MMEditor();

    void set_character(MMCharacter* p_controller) {
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
#endif // MM_EDITOR_H
