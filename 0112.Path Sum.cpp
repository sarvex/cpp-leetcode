/**
 * @brief Check if root-to-leaf path with target sum exists
 * @intuition Track running sum during DFS, check at leaf nodes
 * @approach Recursive DFS accumulating sum, return true at matching leaf
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto hasPathSum(const TreeNode* root, int targetSum) -> bool {
        auto dfs = [targetSum](this auto&& self, const TreeNode* node, int sum) -> bool {
            if (!node) {
                return false;
            }
            sum += node->val;
            if (!node->left && !node->right && sum == targetSum) {
                return true;
            }
            return self(node->left, sum) || self(node->right, sum);
        };
        return dfs(root, 0);
    }
};
