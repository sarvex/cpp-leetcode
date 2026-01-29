/**
 * @brief Find minimum depth using recursive DFS with leaf detection
 * @intuition Min depth is shortest path to a leaf, handle missing children specially
 * @approach If one child is null, recurse on the other; if both exist, take minimum
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
    [[nodiscard]] auto minDepth(TreeNode* root) const -> int {
        if (!root) {
            return 0;
        }
        if (!root->left) {
            return 1 + minDepth(root->right);
        }
        if (!root->right) {
            return 1 + minDepth(root->left);
        }
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};
