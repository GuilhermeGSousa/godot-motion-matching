/**************************************************************************/
/*  spring.hpp                                                            */
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

#ifndef SPRING_HPP
#define SPRING_HPP

#include <math.h>

#include "core/config/project_settings.h"
#include "core/io/resource.h"
#include "core/object/class_db.h"
#include "core/object/method_bind.h"
#include "core/object/ref_counted.h"

namespace Spring {

static constexpr real_t Ln2 = 0.69314718056;

static real_t inline square(real_t x) {
    return x * x;
}

static inline real_t fast_negexp(real_t x) {
    return 1.0 / (1.0 + x + 0.48 * x * x + 0.235 * x * x * x);
}

// static Vector3 damp_adjustment_exact(Vector3 g, real_t halflife, real_t dt, real_t eps = 1e-8) {
//     real_t factor = 1.0 - fast_negexp((Spring::Ln2 * dt) / (halflife + eps));
//     return g * factor;
// }

// static Quaternion damp_adjustment_exact_quat(Quaternion g, real_t halflife, real_t dt, real_t eps = 1e-8) {
//     real_t factor = 1.0 - fast_negexp((Spring::Ln2 * dt) / (halflife + eps));
//     return Quaternion().slerp(g, factor).normalized();
// }

// static Variant damper_exponential(Variant variable, Variant goal, real_t damping, real_t dt) {
//     real_t ft = 1.0 / (real_t)ProjectSettings::get_singleton()->get("physics/common/physics_ticks_per_second");
//     real_t factor = 1.0 - pow(1.0 / (1.0 - ft * damping), -dt / ft);
//     return Math::lerp(variable, goal, factor);
// }

static inline Variant damper_exact(Variant variable, Variant goal, real_t halflife, real_t dt, real_t eps = 1e-5) {
    return Math::lerp(variable, goal, 1.0 - fast_negexp((Spring::Ln2 * dt) / (halflife + eps)));
}

static inline real_t halflife_to_damping(real_t halflife, real_t eps = 1e-5) {
    return (4.0 * Ln2) / (halflife + eps);
}

static inline real_t halflife_to_duration(real_t halflife, real_t initial_value = 1.0, real_t eps = 1e-5) {
    return halflife * (log(eps / initial_value) / log(0.5));
}

static inline real_t damping_to_halflife(real_t damping, real_t eps = 1e-5) {
    return (4.0 * Ln2) / (damping + eps);
}

static inline real_t frequency_to_stiffness(real_t frequency) {
    return square(2.0 * Math_PI * frequency);
}

static inline real_t stiffness_to_frequency(real_t stiffness) {
    return sqrt(stiffness) / (2.0 * Math_PI);
}

static inline real_t critical_halflife(real_t frequency) {
    return damping_to_halflife(sqrt(frequency_to_stiffness(frequency) * 4.0));
}

static inline real_t critical_frequency(real_t halflife) {
    return stiffness_to_frequency(square(halflife_to_damping(halflife)) / 4.0);
}

static inline real_t damping_ratio_to_stiffness(real_t ratio, real_t damping) {
    return square(damping / (ratio * 2.0));
}

static inline real_t damping_ratio_to_damping(real_t ratio, real_t stiffness) {
    return ratio * 2.0 * sqrt(stiffness);
}

static inline real_t maximum_spring_velocity_to_halflife(real_t x, real_t x_goal, real_t v_max) {
    return damping_to_halflife(2.0 * ((v_max / (x_goal - x)) * exp(1.0)));
}

static inline Quaternion quat_exp(Vector3 v, real_t eps = 1e-8) {
    real_t halfangle = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

    if (halfangle < eps) {
        Quaternion q{};
        q.w = 1.0;
        q.x = v.x;
        q.y = v.y;
        q.z = v.z;
        return q.normalized();
    } else {
        real_t c = cosf(halfangle);
        real_t s = sinf(halfangle) / halfangle;
        Quaternion q{};
        q.w = c;
        q.x = s * v.x;
        q.y = s * v.y;
        q.z = s * v.z;
        return q.normalized();
    }
}
template <typename T>
static inline T clampf(T x, T min, T max) {
    static_assert(std::is_arithmetic_v<T>, "Must be arithmetic");
    return x > max ? max : x < min ? min
                                   : x;
}

static inline Quaternion quat_abs(Quaternion q) {
    return (q.w < 0.0 ? -q : q).normalized();
}

static inline Vector3 quat_log(Quaternion q, real_t eps = 1e-8) {
    real_t length = sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
    if (length < eps) {
        return Vector3(q.x, q.y, q.z);
    } else {
        real_t halfangle = acosf(clampf(q.w, real_t(-1.0), real_t(1.0)));
        return halfangle * (Vector3(q.x, q.y, q.z) / length);
    }
}

static inline Quaternion quat_from_scaled_angle_axis(Vector3 v, real_t eps = 1e-8) {
    return quat_exp(v / 2.0, eps).normalized();
}

static inline Vector3 quat_to_scaled_angle_axis(Quaternion q, real_t eps = 1e-8) {
    return 2.0 * quat_log(q, eps);
}

static inline Vector3 quat_differentiate_angular_velocity(Quaternion next, Quaternion curr, real_t dt, real_t eps = 1e-8) {
    return quat_to_scaled_angle_axis(quat_abs(next * curr.inverse()), eps) / dt;
}

// static void _spring_damper_exact(real_t& x, real_t& v, real_t x_goal, real_t v_goal, real_t damping_ratio, real_t halflife, real_t dt, real_t eps = 1e-5) {
//     real_t g = x_goal;
//     real_t q = v_goal;
//     real_t d = halflife_to_damping(halflife);
//     real_t s = damping_ratio_to_stiffness(damping_ratio, d);
//     real_t c = g + (d * q) / (s + eps);
//     real_t y = d / 2.0;

//     if (std::abs(s - (d * d) / 4.0) < eps) { // Critically Damped
//         real_t j0 = x - c;
//         real_t j1 = v + j0 * y;
//         real_t eydt = std::exp(-y * dt);
//         x = j0 * eydt + dt * j1 * eydt + c;
//         v = -y * j0 * eydt - y * dt * j1 * eydt + j1 * eydt;
//     } else if (s - (d * d) / 4.0 > 0.0) { // Under Damped
//         real_t w = std::sqrt(s - (d * d) / 4.0);
//         real_t j = std::sqrt(std::pow(v + y * (x - c), 2) / (std::pow(w, 2) + eps) + std::pow(x - c, 2));
//         real_t p = std::atan((v + (x - c) * y) / (-(x - c) * w + eps));

//         // j = (x - c) > 0.0 ? j : -j;
//         j = (x - c) > 0.0 ? j : -j;

//         real_t eydt = std::exp(-y * dt);

//         x = j * eydt * std::cos(w * dt + p) + c;
//         v = -y * j * eydt * std::cos(w * dt + p) - w * j * eydt * std::sin(w * dt + p);
//     } else if (s - (d * d) / 4.0 < 0.0) { // Over Damped
//         real_t y0 = (d + std::sqrt(std::pow(d, 2) - 4.0 * s)) / 2.0;
//         real_t y1 = (d - std::sqrt(std::pow(d, 2) - 4.0 * s)) / 2.0;
//         real_t j1 = (c * y0 - x * y0 - v) / (y1 - y0);
//         real_t j0 = x - j1 - c;

//         real_t ey0dt = std::exp(-y0 * dt);
//         real_t ey1dt = std::exp(-y1 * dt);

//         x = j0 * ey0dt + j1 * ey1dt + c;
//         v = -y0 * j0 * ey0dt - y1 * j1 * ey1dt;
//     }
// }

static void _critical_spring_damper_exact(real_t& x, real_t& v, real_t x_goal, real_t v_goal, real_t halflife, real_t dt) {
    real_t g = x_goal;
    real_t q = v_goal;
    real_t d = halflife_to_damping(halflife);
    real_t c = g + (d * q) / ((d * d) / 4.0);
    real_t y = d / 2.0;
    real_t j0 = x - c;
    real_t j1 = v + j0 * y;
    real_t eydt = fast_negexp(y * dt);
    x = eydt * (j0 + j1 * dt) + c;
    v = eydt * (v - j1 * y * dt);
}

static inline PackedFloat32Array critical_spring_damper_exact(real_t x, real_t v, real_t x_goal, real_t v_goal, real_t halflife, real_t dt) {
    _critical_spring_damper_exact(x, v, x_goal, v_goal, halflife, dt);
    PackedFloat32Array result;
    result.append(x);
    result.append(v);
    return result;
}

static void _simple_spring_damper_exact(real_t& x, real_t& v, real_t x_goal, real_t halflife, real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;
    real_t j0 = x - x_goal;
    real_t j1 = v + j0 * y;
    real_t eydt = fast_negexp(y * dt);
    x = eydt * (j0 + j1 * dt) + x_goal;
    v = eydt * (v - j1 * y * dt);
}
static void _simple_spring_damper_exact(Vector3& x, Vector3& v, const Vector3 x_goal, const real_t halflife, const real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;
    Vector3 j0 = x - x_goal;
    Vector3 j1 = v + j0 * y;
    real_t eydt = fast_negexp(y * dt);

    x = eydt * (j0 + j1 * dt) + x_goal;
    v = eydt * (v - j1 * y * dt);
}

static void _simple_spring_damper_exact(Quaternion& x, Vector3& v, const Quaternion x_goal, const real_t halflife, const real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;

    Vector3 j0 = quat_to_scaled_angle_axis(quat_abs(x * x_goal.inverse()));
    Vector3 j1 = v + j0 * y;

    real_t eydt = fast_negexp(y * dt);

    x = quat_from_scaled_angle_axis(eydt * (j0 + j1 * dt)) * x_goal;
    v = eydt * (v - j1 * y * dt);
}

static inline Array simple_spring_damper_exact(Variant x, Variant v, Variant x_goal, real_t halflife, real_t dt) {
    Array result;
    if (x.get_type() == Variant::Type::VECTOR3 && v.get_type() == Variant::Type::VECTOR3 && x_goal.get_type() == Variant::Type::VECTOR3) {
        Vector3 pos = (Vector3)x, vel = (Vector3)v, goal = (Vector3)x_goal;
        _simple_spring_damper_exact(pos, vel, goal, halflife, dt);
        result.append(pos);
        result.append(vel);
    } else if (x.get_type() == Variant::Type::QUATERNION && v.get_type() == Variant::Type::VECTOR3 && x_goal.get_type() == Variant::Type::QUATERNION) {
        Quaternion pos = (Quaternion)x;
        Vector3 vel = (Vector3)v;
        Quaternion goal = (Quaternion)x_goal;
        _simple_spring_damper_exact(pos, vel, goal, halflife, dt);
        result.append(pos);
        result.append(vel);
    } else if (x.get_type() == Variant::Type::FLOAT && v.get_type() == Variant::Type::FLOAT && v.get_type() == Variant::Type::FLOAT) {
        real_t pos = (real_t)x;
        real_t vel = (real_t)v, goal = (real_t)x_goal;
        _simple_spring_damper_exact(pos, vel, goal, halflife, dt);
        result.append(pos);
        result.append(vel);
    }

    return result;
}

static inline void _decay_spring_damper_exact(real_t& x, real_t& v, real_t halflife, real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;
    real_t j1 = v + x * y;
    real_t eydt = fast_negexp(y * dt);
    x = eydt * (x + j1 * dt);
    v = eydt * (v - j1 * y * dt);
}
static inline void _decay_spring_damper_exact(Vector3& x, Vector3& v, real_t halflife, real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;
    Vector3 j1 = v + x * y;
    real_t eydt = fast_negexp(y * dt);
    x = eydt * (x + j1 * dt);
    v = eydt * (v - j1 * y * dt);
}
static inline void _decay_spring_damper_exact(Quaternion& x, Vector3& v, const real_t halflife, const real_t dt) {
    real_t y = halflife_to_damping(halflife) / 2.0;

    Vector3 j0 = quat_to_scaled_angle_axis(x);
    Vector3 j1 = v + j0 * y;

    real_t eydt = fast_negexp(y * dt);

    x = quat_from_scaled_angle_axis(eydt * (j0 + j1 * dt));
    v = eydt * (v - j1 * y * dt);
}
static inline Array decay_spring_damper_exact(Variant x, Variant v, real_t halflife, real_t dt) {
    Array result;
    if (x.get_type() == Variant::Type::VECTOR3 && v.get_type() == Variant::Type::VECTOR3) {
        Vector3 pos = (Vector3)x, vel = (Vector3)v;
        _decay_spring_damper_exact(pos, vel, halflife, dt);
        result.append(pos);
        result.append(vel);
    } else if (x.get_type() == Variant::Type::QUATERNION && v.get_type() == Variant::Type::VECTOR3) {
        Quaternion pos = (Quaternion)x;
        Vector3 vel = (Vector3)v;
        _decay_spring_damper_exact(pos, vel, halflife, dt);
        result.append(pos);
        result.append(vel);
    } else if (x.get_type() == Variant::Type::FLOAT && v.get_type() == Variant::Type::FLOAT) {
        real_t pos = (real_t)x;
        real_t vel = (real_t)v;
        _decay_spring_damper_exact(pos, vel, halflife, dt);
        result.append(pos);
        result.append(vel);
    }

    return result;
}

//	Reach the x_goal at timed t_goal in the future
//	Apprehension parameter controls how far into the future we try to track
// the linear interpolation
static void _timed_spring_damper_exact(real_t& x, real_t& v, real_t& xi, const real_t x_goal, const real_t t_goal, const real_t halflife, const real_t& dt, real_t apprehension = 2.0) {
    const real_t min_time = t_goal > dt ? t_goal : dt;

    const real_t v_goal = (x_goal - xi) / min_time;

    const real_t t_goal_future = dt + apprehension * halflife;
    const real_t x_goal_future = t_goal_future < t_goal ? xi + v_goal * t_goal_future : x_goal;

    _simple_spring_damper_exact(x, v, x_goal_future, halflife, dt);
    xi += v_goal * dt;
}
static inline PackedFloat32Array timed_spring_damper_exact(real_t x, real_t v, real_t xi, const real_t x_goal, const real_t t_goal, const real_t halflife, const real_t dt, const real_t apprehension = 2.0) {
    PackedFloat32Array result;
    _timed_spring_damper_exact(x, v, xi, x_goal, t_goal, halflife, dt, apprehension);
    result.append(x);
    result.append(v);
    result.append(xi);
    return result;
}

// static Dictionary character_update(Vector3 pos, Vector3 vel, Vector3 acc, Quaternion quaternion, Vector3 angular_velocity, Vector3 v_goal, Quaternion q_goal, real_t halflife_vel, real_t halflife_rot, real_t dt) {
//     Dictionary answer;
//     {
//         real_t y = halflife_to_damping(halflife_vel) / 2.0;
//         Vector3 j0 = vel - v_goal;
//         Vector3 j1 = acc + j0 * y;
//         real_t eydt = fast_negexp(y * dt);

//         answer["world_position"] = eydt * ((-j1 / (y * y)) + ((-j0 - j1 * dt) / y)) + (j1 / (y * y)) + j0 / y + v_goal * dt + pos;
//         answer["velocity"] = eydt * (j0 + j1 * dt) + v_goal;
//         answer["acceleration"] = eydt * (acc - j1 * y * dt);
//     }
//     {
//         real_t y = halflife_to_damping(halflife_rot) / 2.0;
//         Vector3 j0 = (quaternion * q_goal.inverse()).get_euler();
//         Vector3 j1 = angular_velocity + j0 * y;
//         real_t eydt = fast_negexp(y * dt);
//         Vector3 axis = (j0 + j1 * dt).normalized();
//         real_t angle = (j0 + j1 * dt).length() * eydt;
//         Quaternion rotation(axis, angle);
//         answer["quaternion"] = (Quaternion(axis, angle) * q_goal).normalized();
//         answer["angular_velocity"] = eydt * (angular_velocity - j1 * y * dt);
//         answer["delta"] = dt;
//     }
//     return answer;
// }

// static Dictionary character_predict(Vector3 x, Vector3 v, Vector3 a, Quaternion q, Vector3 angular_v, Vector3 v_goal, Quaternion q_goal, real_t halflife_v, real_t halflife_q, const PackedFloat32Array dts) {
//     Dictionary answer;
//     for (int i = 0; i < dts.size(); i++) {
//         real_t dt = dts[i];
//         answer[i] = character_update(x, v, a, q, angular_v, v_goal, q_goal, halflife_v, halflife_q, dt);
//     }
//     return answer;
// }

static inline void inertialize_transition(Vector3& off_x, Vector3& off_v, const Vector3 src_x, const Vector3 src_v, const Vector3 dst_x, const Vector3 dst_v) {
    off_x = (src_x + off_x) - dst_x;
    off_v = (src_v + off_v) - dst_v;
}

static inline void inertialize_update(Vector3& out_x, Vector3& out_v, Vector3& off_x, Vector3& off_v, const Vector3 in_x, const Vector3 in_v, const real_t halflife, const real_t dt) {
    Spring::_decay_spring_damper_exact(off_x, off_v, halflife, dt);
    out_x = in_x + off_x;
    out_v = in_v + off_v;
}

static inline void inertialize_transition(Quaternion& off_x, Vector3& off_v, const Quaternion src_x, const Vector3 src_v, const Quaternion dst_x, const Vector3 dst_v) {
    off_x = Spring::quat_abs((off_x * src_x) * dst_x.inverse()).normalized();
    off_v = (off_v + src_v) - dst_v;
}
static inline void inertialize_update(Quaternion& out_x, Vector3& out_v, Quaternion& off_x, Vector3& off_v, const Quaternion in_x, const Vector3 in_v, const real_t halflife, const real_t dt) {
    Spring::_decay_spring_damper_exact(off_x, off_v, halflife, dt);
    out_x = (off_x * in_x).normalized();
    out_v = off_v + off_x.xform(in_v);
}

static inline Vector3 calculate_offset_vec3(const Vector3 src_x, const Vector3 dst_x, const Vector3 off_x = Vector3()) {
    return (src_x + off_x) - dst_x;
}
static inline Quaternion calculate_offset_quat(const Quaternion src_q, const Quaternion dst_q, const Quaternion off_q = Quaternion()) {
    return Spring::quat_abs((off_q * src_q) * dst_q.inverse());
}

static inline Dictionary binded_inertia_transition(const Vector3 off_x, const Vector3 off_v, const Vector3 src_x, const Vector3 src_v, const Vector3 dst_x, const Vector3 dst_v, const Quaternion off_q, const Vector3 off_a, const Quaternion src_q, const Vector3 src_a, const Quaternion dst_q, const Vector3 dst_a) {
    Dictionary result;
    result["position_offset"] = (src_x + off_x) - dst_x;
    result["velocity_offset"] = (src_v + off_v) - dst_v;
    result["rotation_offset"] = Spring::quat_abs((off_q * src_q) * dst_q.inverse());
    result["angular_offset"] = (off_a + src_a) - dst_a;
    return result;
}
}; // namespace Spring

#endif // SPRING_HPP
