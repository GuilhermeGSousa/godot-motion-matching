#pragma once

#include <cmath>
#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/bone_map.hpp>
#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <numeric>

#include "godot_cpp/core/math.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include "spring.hpp"

using namespace godot;

struct kform {
    Quaternion rot = Quaternion();
    Vector3 pos = Vector3();
    Vector3 scl = Vector3(1.0, 1.0, 1.0);
    Vector3 vel = Vector3();
    Vector3 ang = Vector3();
    Vector3 svl = Vector3();

    kform() = default;
    ~kform() = default;

    kform(Transform3D tr)
        : pos{tr.origin}, rot{tr.basis.get_rotation_quaternion()}, scl{tr.basis.get_scale()}, vel{}, ang{}, svl{} {
    }

    kform(Vector3 p, Quaternion r, Vector3 s, Vector3 lv, Vector3 av, Vector3 sv)
        : pos{p}, rot{r}, scl{s}, vel{lv}, ang{av}, svl{sv} {
    }

    kform(Ref<SkeletonProfile> skel, NodePath bonepath, Ref<Animation> anim, double time)
        : kform{skel->get_reference_pose(skel->find_bone(bonepath.get_concatenated_subnames()))} {
        auto tpos = anim->find_track(bonepath, Animation::TrackType::TYPE_POSITION_3D);
        auto trot = anim->find_track(bonepath, Animation::TrackType::TYPE_ROTATION_3D);
        auto tscl = anim->find_track(bonepath, Animation::TrackType::TYPE_SCALE_3D);
        kform s1 = *this;
        if (tpos != -1) {
            pos = anim->position_track_interpolate(tpos, time);
            s1.pos = anim->position_track_interpolate(tpos, time + dt);
        }
        if (trot != -1) {
            rot = anim->rotation_track_interpolate(trot, time);
            s1.rot = anim->rotation_track_interpolate(trot, time + dt);
        }
        if (tscl != -1) {
            scl = anim->scale_track_interpolate(tscl, time);
            s1.scl = anim->scale_track_interpolate(tscl, time + dt);
        }
        *this = finite_difference(*this, s1, dt);
    }

    enum Space { Local, Model, RootMotion, Global };

    kform(Ref<SkeletonProfile> skel, Ref<Animation> anim, double time, NodePath bonepath, Space space)
        : kform(skel->get_reference_pose(skel->find_bone(bonepath.get_concatenated_subnames()))) {
        switch (space) {
        case Local:
            _local(skel, anim, time, bonepath);
            break;
        case Model:
            _model(skel, anim, time, bonepath);
            break;
        case RootMotion:
            _root(skel, anim, time, bonepath);
            break;
        case Global:
            _global(skel, anim, time, bonepath);
            break;
        }
    }
    static constexpr double dt = 0.016;
    // DONE
    void _local(Ref<SkeletonProfile> skel, Ref<Animation> anim, double time, NodePath bonepath) {
        *this = skel->get_reference_pose(skel->find_bone(bonepath.get_concatenated_subnames()));
        auto tpos = anim->find_track(bonepath, Animation::TrackType::TYPE_POSITION_3D);
        auto trot = anim->find_track(bonepath, Animation::TrackType::TYPE_ROTATION_3D);
        auto tscl = anim->find_track(bonepath, Animation::TrackType::TYPE_SCALE_3D);
        kform s1 = *this;
        if (tpos != -1) {
            pos = anim->position_track_interpolate(tpos, time);
            s1.pos = anim->position_track_interpolate(tpos, time + dt);
        }
        if (trot != -1) {
            rot = anim->rotation_track_interpolate(trot, time);
            s1.rot = anim->rotation_track_interpolate(trot, time + dt);
        }
        if (tscl != -1) {
            scl = anim->scale_track_interpolate(tscl, time);
            s1.scl = anim->scale_track_interpolate(tscl, time + dt);
        }
        *this = finite_difference(*this, s1, dt);
    }
    // Done
    void _model(Ref<SkeletonProfile> skel, Ref<Animation> anim, double time, NodePath bonepath) {
        _global(skel, anim, time, bonepath);
        auto root = kform{};
        root._local(skel, anim, time, bonepath.get_concatenated_names() + String(":") + skel->get_root_bone());
        *this = *this / root;
    }
    // TODO
    void _root(Ref<SkeletonProfile> skel, Ref<Animation> anim, double time, NodePath bonepath) {
        _global(skel, anim, time, bonepath);
        auto root = kform{};
        root._local(skel, anim, time, bonepath.get_concatenated_names() + String(":") + skel->get_root_bone());
        *this = root / *this;
    }
    // DONE
    void _global(Ref<SkeletonProfile> skel, Ref<Animation> anim, double time, NodePath bonepath) {
        kform s1 = *this;

        std::vector<kform> locals{};
        String skelpath = bonepath.get_concatenated_names();
        String bone = bonepath.get_concatenated_subnames();
        int bone_id = skel->find_bone(bone);

        do {
            kform l = *this;
            l._local(skel, anim, time, skelpath + ':' + UtilityFunctions::str(bone));
            locals.push_back(l);

            bone = skel->get_bone_parent(bone_id);
            bone_id = skel->find_bone(bone);
        } while (bone_id != -1);

        *this = std::accumulate(locals.rbegin(), locals.rend(), kform{},
                                [](const kform& acc, const kform& i) { return acc * i; });
    }

    static Vector3 _log(Vector3 v) {
        return Vector3(std::log(v.x), std::log(v.y), std::log(v.z));
    }

    kform& finite_difference(kform input_next, real_t _dt) {
        vel = (input_next.pos - pos) / _dt;

        ang = Spring::quat_to_scaled_angle_axis(Spring::quat_abs(input_next.rot * rot.inverse())) / _dt;

        svl = _log(input_next.scl / scl) / _dt;
        return *this;
    }

    static kform finite_difference(const kform& input_curr, const kform& input_next, real_t _dt) {
        kform out = input_curr;
        out.vel = (input_next.pos - out.pos) / _dt;

        out.ang = Spring::quat_to_scaled_angle_axis(Spring::quat_abs(input_next.rot * out.rot.inverse())) / _dt;

        out.svl = _log(input_next.scl / out.scl) / _dt;
        return out;
    }

    friend kform operator*(const kform v, const kform w) {
        kform out;
        out.pos = v.rot.xform(w.pos * v.scl) + v.pos;
        out.rot = v.rot * w.rot;
        out.scl = w.scl * v.scl;
        out.vel = v.rot.xform(w.vel * v.scl) + v.vel + v.ang.cross(v.rot.xform(w.pos * v.scl)) +
            v.rot.xform(w.pos * v.scl * v.svl);
        out.ang = v.rot.xform(w.ang) + v.ang;
        out.svl = w.svl + v.svl;
        return out;
    }
    friend kform operator/(const kform v, const kform w) {
        kform out;
        out.pos = v.rot.xform_inv(w.pos - v.pos);
        out.rot = v.rot.inverse() * w.rot;
        out.scl = w.scl / v.scl;
        out.vel = v.rot.xform_inv(w.vel - v.vel - v.ang.cross(v.rot.xform(out.pos * v.scl))) -
            v.rot.xform(out.pos * v.scl * v.svl);
        out.ang = v.rot.xform_inv(w.ang - v.ang);
        out.svl = w.svl - v.svl;
        return out;
    }
    kform inverse() const {
        return kform() / (*this);
    }
};

struct kforms {
    template <typename T>
    using b_vector = std::vector<T>;
    b_vector<Vector3> pos;    // Position
    b_vector<Quaternion> rot; // Rotation
    b_vector<Vector3> scl;    // Scale
    b_vector<Vector3> vel;    // Linear Velocity
    b_vector<Vector3> ang;    // Angular Velocity
    b_vector<Vector3> svl;    // Scalar Velocity

    kforms(std::size_t N)
        : pos(N, Vector3()), rot(N, Quaternion()), scl(N, Vector3(1, 1, 1)), vel(N, Vector3()), ang(N, Vector3()),
          svl(N, Vector3()) {
    }

    Transform3D get_transform(std::size_t N) {
        return Transform3D(Basis(rot[N], scl[N]), pos[N]);
    }

    void reserve(std::size_t N) {
        pos.reserve(N);
        rot.reserve(N);
        scl.reserve(N);
        vel.reserve(N);
        ang.reserve(N);
        svl.reserve(N);
    }

    std::size_t count() const noexcept {
        return pos.size();
    }

    inline const kform operator[](const std::size_t N) noexcept {
        kform out{};
        out.pos = pos[N];
        out.rot = rot[N];
        out.scl = scl[N];
        out.vel = vel[N];
        out.ang = ang[N];
        out.svl = svl[N];
        return out;
    }

    void reset(const std::size_t N) {
        pos[N] = Vector3();
        rot[N] = Quaternion();
        scl[N] = Vector3(1, 1, 1);
        vel[N] = Vector3();
        ang[N] = Vector3();
        svl[N] = Vector3();
    }
};