/**
 * @brief Flatten binary tree to linked list in-place using Morris-like traversal
 * @intuition Move left subtree to right, connecting rightmost of left to original right
 * @approach Iteratively move left subtrees to right, threading through rightmost nodes
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    static auto flatten(TreeNode* root) -> void {
        while (root != nullptr) {
            if (root->left != nullptr) {
                TreeNode* predecessor = root->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
