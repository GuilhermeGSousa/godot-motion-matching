#pragma once

#include <godot_cpp/classes/ref_counted.hpp>

#include "common.h"

using namespace godot;

class MMTrajectoryPoint : public RefCounted {
    GDCLASS(MMTrajectoryPoint, RefCounted)

public:
    MMTrajectoryPoint();
    virtual ~MMTrajectoryPoint();

protected:
    static void _bind_methods();

public:
    GETSET(Vector3, position)
    GETSET(Vector3, velocity)
};