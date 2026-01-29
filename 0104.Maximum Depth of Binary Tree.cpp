/**
 * @brief Recursive depth calculation for binary tree
 * @intuition Max depth is 1 plus the max of left and right subtree depths
 * @approach Recursively compute depth of subtrees and return max plus one
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto maxDepth(const TreeNode* root) -> int {
        if (!root) {
            return 0;
        }
        const int leftDepth = maxDepth(root->left);
        const int rightDepth = maxDepth(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
};
