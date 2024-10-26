/**************************************************************************/
/*  mm_clamp_synchronizer.cpp                                             */
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

#include "synchronizers/mm_clamp_synchronizer.h"

#include "mm_character.h"

MMSyncResult MMClampSynchronizer::sync(const MMCharacter* controller, const Node3D* character, float delta_time) {
    MMSyncResult result;

    result.controller_position = controller->get_global_position();
    result.controller_rotation = controller->get_quaternion();

    const Vector3 position_delta = character->get_global_position() - controller->get_global_position();

    if (position_delta.length() > clamp_distance) {
        result.character_position =
            result.controller_position +
            position_delta.normalized() * clamp_distance;
    } else {
        result.character_position = character->get_global_position();
    }

    result.character_rotation = character->get_quaternion();

    return result;
}

void MMClampSynchronizer::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMClampSynchronizer, Variant::FLOAT, clamp_distance);
}
