#pragma once

#include "editor/plugins/node_3d_editor_gizmos.h"
#include "scene/3d/node_3d.h"

class MMEditorGizmoPlugin : public EditorNode3DGizmoPlugin {
    GDCLASS(MMEditorGizmoPlugin, EditorNode3DGizmoPlugin)

public:
    MMEditorGizmoPlugin();

	virtual bool has_gizmo(Node3D *p_spatial) override;
    virtual String get_gizmo_name() const override;
	virtual void redraw(EditorNode3DGizmo *p_gizmo) override;
    virtual int32_t get_priority() const override {
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