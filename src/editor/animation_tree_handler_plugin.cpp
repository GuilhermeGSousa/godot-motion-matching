#include "animation_tree_handler_plugin.h"

AnimationTreeHandlerPlugin* AnimationTreeHandlerPlugin::_singleton = nullptr;

AnimationTreeHandlerPlugin::AnimationTreeHandlerPlugin() {
    _singleton = this;
    _animation_tree = nullptr;
}

bool AnimationTreeHandlerPlugin::_handles(Object* p_node) const {
    return Object::cast_to<AnimationTree>(p_node) != nullptr;
}

void AnimationTreeHandlerPlugin::_edit(Object* p_object) {
    _animation_tree = Object::cast_to<AnimationTree>(p_object);
}

AnimationTreeHandlerPlugin* AnimationTreeHandlerPlugin::get_singleton() {
    return _singleton;
}

void AnimationTreeHandlerPlugin::_bind_methods() {
}