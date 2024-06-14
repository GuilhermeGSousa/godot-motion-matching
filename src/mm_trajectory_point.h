#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include "common.h"

using namespace godot;

struct MMTrajectoryPoint {
    Vector3 position;
    Vector3 velocity;
    float facing_angle;
};

class MMTrajectoryPointRC : public RefCounted {
    GDCLASS(MMTrajectoryPointRC, RefCounted)

public:
    MMTrajectoryPointRC();
    MMTrajectoryPointRC(MMTrajectoryPoint point) : _point(point){};
    virtual ~MMTrajectoryPointRC();

public:
    const Vector3& get_position() const {
        return _point.position;
    }

    float get_facing_angle() const {
        return _point.facing_angle;
    }

protected:
    static void _bind_methods();

private:
    MMTrajectoryPoint _point;
};