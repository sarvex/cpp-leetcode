/**
 * @brief Check if root-to-leaf path with target sum exists
 * @intuition Track running sum during DFS, check at leaf nodes
 * @approach Recursive DFS accumulating sum, return true at matching leaf
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <functional>

using std::function;

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
    [[nodiscard]] auto hasPathSum(TreeNode* root, int targetSum) const -> bool {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int sum) -> bool {
            if (!node) {
                return false;
            }
            sum += node->val;
            if (!node->left && !node->right && sum == targetSum) {
                return true;
            }
            return dfs(node->left, sum) || dfs(node->right, sum);
        };
        return dfs(root, 0);
    }
};
