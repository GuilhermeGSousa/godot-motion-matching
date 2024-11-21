#ifndef MM_EDITOR_GIZMO_PLUGIN_H
#define MM_EDITOR_GIZMO_PLUGIN_H

#include <godot_cpp/classes/editor_node3d_gizmo_plugin.hpp>
#include <godot_cpp/classes/node3d.hpp>

using namespace godot;

class MMEditorGizmoPlugin : public EditorNode3DGizmoPlugin {
    GDCLASS(MMEditorGizmoPlugin, EditorNode3DGizmoPlugin)

public:
    MMEditorGizmoPlugin();

    virtual bool _has_gizmo(Node3D* p_for_node_3d) const override;
    virtual String _get_gizmo_name() const override;
    virtual void _redraw(const Ref<EditorNode3DGizmo>& p_gizmo) override;
    virtual int32_t _get_priority() const override {
        return -1;
    }

    void on_anim_viz_requested(String p_animation_lib, String p_animation_name, int32_t p_pose_index);

protected:
    static void _bind_methods();

private:
    String _animation_lib;
    String _animation_name;
    int32_t _pose_index;
};
#endif // MM_EDITOR_GIZMO_PLUGIN_H
