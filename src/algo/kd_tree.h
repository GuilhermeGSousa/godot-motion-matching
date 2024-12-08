#pragma once

#include "godot_cpp/variant/packed_float32_array.hpp"
#include "godot_cpp/variant/packed_int32_array.hpp"

#include <functional>
#include <vector>

using namespace godot;

class KDTree {

public:
    KDTree(const float* data, int point_dimension, int point_count);
    KDTree(int point_count);
    ~KDTree();

    int search_nn(const float* pose_data, const float* query, const std::vector<float>& dimension_weigths) const;
    std::vector<int> search_knn(const float* pose_data,
                                const float* query,
                                const std::vector<float>& dimension_weigths,
                                int k) const;

    PackedInt32Array get_node_indices() const;

    void rebuild_tree(int point_count, const PackedInt32Array& indices);

private:
    struct TreeNode {

        int axis;
        TreeNode* children[2];
        int index;
    };

    void _build_tree(const float* data, int point_dimension, int point_count);
    TreeNode* _build_tree_recursive(const float* data, int* indices, int npoints, int current_depth);

    void _clear_tree();
    void _clear_tree_recursive(TreeNode* node);

    void _search_nn_recursive(const float* pose_data, const float* query, const std::vector<float>& dimension_weigths, const TreeNode* node, float& best_distance, int& best_index, int depth) const;

    void _get_node_indices_recursive(const TreeNode* node, PackedInt32Array& indices) const;

    void _rebuild_tree_recursive(TreeNode*& node, const PackedInt32Array& indices, int& value_index, int current_depth);
    const int _point_dim = 0;
    TreeNode* _root = nullptr;
};