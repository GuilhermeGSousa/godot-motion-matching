#include "kd_tree.h"

#include <algorithm>
#include <limits>
#include <numeric>

KDTree::KDTree(const float* data, int point_dimension, int point_count)
    : _point_dim(point_dimension),
      _root(nullptr) {

    _build_tree(data, point_dimension, point_count);
}

KDTree::KDTree(int point_count)
    : _point_dim(point_count),
      _root(nullptr) {
}

KDTree::~KDTree() {
    _clear_tree();
}

int KDTree::search_nn(
    const float* pose_data,
    const float* query,
    const std::vector<float>& dimension_weigths) const {
    float best_distance_squared = std::numeric_limits<float>::max();
    int best_index = -1;
    _search_nn_recursive(pose_data, query, dimension_weigths, _root, best_distance_squared, best_index, 0);
    return best_index;
}

std::vector<int> KDTree::search_knn(const float* pose_data,
                                    const float* query,
                                    const std::vector<float>& dimension_weigths,
                                    int k) const {
    // TODO
    return std::vector<int>();
}

PackedInt32Array KDTree::get_node_indices() const {
    PackedInt32Array indices;
    _get_node_indices_recursive(_root, indices);
    return std::move(indices);
}

void KDTree::rebuild_tree(int point_count, const PackedInt32Array& indices) {
    _clear_tree();

    if (_root) {
        delete _root;
    }

    int value_index = 0;
    _rebuild_tree_recursive(_root, indices, value_index, 0);
}

void KDTree::_build_tree(const float* data, int point_dimension, int point_count) {

    std::vector<int> indices(point_count);
    std::iota(std::begin(indices), std::end(indices), 0);
    _root = _build_tree_recursive(data, indices.data(), point_count, 0);
}

KDTree::TreeNode* KDTree::_build_tree_recursive(const float* data, int* indices, int npoints, int current_depth) {

    if (npoints <= 0) {
        return nullptr;
    }

    KDTree::TreeNode* node = new KDTree::TreeNode();

    const int axis = current_depth % _point_dim;
    node->axis = axis;

    int mid_index = (npoints - 1) / 2;
    std::nth_element(
        indices,
        indices + mid_index,
        indices + npoints,
        [this, &data, &axis](int lhs, int rhs) {
            return data[lhs * _point_dim + axis] < data[rhs * _point_dim + axis];
        });
    data[indices[mid_index] * _point_dim + axis];
    node->index = indices[mid_index];
    node->children[0] = _build_tree_recursive(data, indices, mid_index, current_depth + 1);
    node->children[1] = _build_tree_recursive(data, indices + mid_index + 1, npoints - mid_index - 1, current_depth + 1);

    return node;
}

void KDTree::_clear_tree() {
    _clear_tree_recursive(_root);
}

void KDTree::_clear_tree_recursive(TreeNode* node) {
    if (!node) {
        return;
    }

    _clear_tree_recursive(node->children[0]);
    _clear_tree_recursive(node->children[1]);

    delete node;
}

void KDTree::_search_nn_recursive(
    const float* pose_data,
    const float* query,
    const std::vector<float>& dimension_weigths,
    const TreeNode* node,
    float& best_distance_squared,
    int& best_index,
    int depth) const {

    if (!node) {
        return;
    }

    float dist_squared = 0.0f;
    for (int i = 0; i < _point_dim; i++) {
        float diff = pose_data[node->index * _point_dim + i] - query[i];
        dist_squared += diff * diff * dimension_weigths[i];
    }

    if (dist_squared < best_distance_squared) {
        best_distance_squared = dist_squared;
        best_index = node->index;
    }
    const int axis = depth % _point_dim;
    const float diff = query[axis] - pose_data[node->index * _point_dim + axis];
    const TreeNode* near_child = diff < 0 ? node->children[0] : node->children[1];
    const TreeNode* far_child = diff < 0 ? node->children[1] : node->children[0];

    _search_nn_recursive(
        pose_data,
        query,
        dimension_weigths,
        near_child,
        best_distance_squared,
        best_index,
        depth + 1);

    if (diff * diff * dimension_weigths[axis] < best_distance_squared) {
        _search_nn_recursive(
            pose_data,
            query,
            dimension_weigths,
            far_child,
            best_distance_squared,
            best_index,
            depth + 1);
    }
}

void KDTree::_get_node_indices_recursive(const TreeNode* node, PackedInt32Array& indices) const {

    if (!node) {
        indices.push_back(-1);
        return;
    }

    indices.push_back(node->index);
    _get_node_indices_recursive(node->children[0], indices);
    _get_node_indices_recursive(node->children[1], indices);
}

void KDTree::_rebuild_tree_recursive(TreeNode*& node, const PackedInt32Array& indices, int& value_index, int current_depth) {
    if (value_index >= indices.size() || indices[value_index] == -1) {
        value_index++;
        return;
    }

    node = new TreeNode();
    node->children[0] = nullptr;
    node->children[1] = nullptr;
    node->index = indices[value_index];
    node->axis = current_depth % _point_dim;

    value_index++;
    _rebuild_tree_recursive(node->children[0], indices, value_index, current_depth + 1);
    _rebuild_tree_recursive(node->children[1], indices, value_index, current_depth + 1);
}
