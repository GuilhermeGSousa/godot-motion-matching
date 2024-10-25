/**************************************************************************/
/*  mm_trajectory_point.h                                                 */
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

#ifndef MM_TRAJECTORY_POINT_H
#define MM_TRAJECTORY_POINT_H

#include "core/object/ref_counted.h"

#include "common.h"

struct MMCollisionState {
    bool on_floor = false;
    Vector3 floor_normal;
    Vector3 floor_position;
    bool against_wall = false;
    Vector3 wall_normal;

    void reset() {
        on_floor = false;
        against_wall = false;
    }
};

struct MMTrajectoryPoint {
    Vector3 position;
    Vector3 velocity;
    float facing_angle;

    MMCollisionState collision_state;

    Transform3D get_transform(const Vector3& up_axis = Vector3(0, 1, 0)) const {
        Transform3D result;
        result.origin = position;
        result.set_basis(Basis(up_axis, facing_angle));
        return result;
    }
};
#endif // MM_TRAJECTORY_POINT_H
