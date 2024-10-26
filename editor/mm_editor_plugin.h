/**************************************************************************/
/*  mm_editor_plugin.h                                                    */
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

#ifndef MM_EDITOR_PLUGIN_H
#define MM_EDITOR_PLUGIN_H

#include "core/os/memory.h"
#include "mm_character.h"
#include "mm_editor.h"
#include "mm_editor_gizmo_plugin.h"

#include "core/input/input_event.h"
#include "core/object/ref_counted.h"
#include "editor/plugins/editor_plugin.h"
#include "modules/motion_matching/src/mm_character.h"
#include "scene/gui/button.h"

class MMEditorPlugin : public EditorPlugin {
    GDCLASS(MMEditorPlugin, EditorPlugin)

public:
    MMEditorPlugin();
    ~MMEditorPlugin();

    virtual void make_visible(bool p_visible) override;
    virtual bool handles(Object* p_node) const override;
    virtual void edit(Object* p_object) override;

private:
    static void _bind_methods() {};

    Ref<MMEditorGizmoPlugin> _gizmo_plugin;

    MMEditor* _editor;
    Button* _bottom_panel_button;
    MMCharacter* _current_controller;
};

#endif // MM_EDITOR_PLUGIN_H
