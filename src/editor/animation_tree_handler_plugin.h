#ifndef ANIMATION_TREE_HANDLER_PLUGIN_H
#define ANIMATION_TREE_HANDLER_PLUGIN_H

#include <godot_cpp/classes/animation_tree.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>

using namespace godot;

// The only reason this class exists is to provide a way for MMAnimationNode
// to access the AnimationTree in editor.
// If a new and better way of doing this comes along, please remove this class!
class AnimationTreeHandlerPlugin : public EditorPlugin {
    GDCLASS(AnimationTreeHandlerPlugin, EditorPlugin)

public:
    AnimationTreeHandlerPlugin();
    virtual ~AnimationTreeHandlerPlugin() = default;

    virtual bool _handles(Object* p_node) const override;
    virtual void _edit(Object* p_object) override;

    static AnimationTreeHandlerPlugin* get_singleton();
    AnimationTree* get_animation_tree() const {
        return _animation_tree;
    }

protected:
    static void _bind_methods();

    static AnimationTreeHandlerPlugin* _singleton;

private:
    AnimationTree* _animation_tree;
};

#endif // ANIMATION_TREE_HANDLER_PLUGIN_H