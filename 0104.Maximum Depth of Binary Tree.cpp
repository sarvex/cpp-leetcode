/**
 * @brief Recursive depth calculation for binary tree
 * @intuition Max depth is 1 plus the max of left and right subtree depths
 * @approach Recursively compute depth of subtrees and return max plus one
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto maxDepth(TreeNode* root) const -> int {
        if (!root) {
            return 0;
        }
        const int leftDepth = maxDepth(root->left);
        const int rightDepth = maxDepth(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
};
