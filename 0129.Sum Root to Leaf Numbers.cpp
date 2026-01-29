/**
 * @brief Sum all root-to-leaf numbers using DFS
 * @intuition Each path forms a number by concatenating node values
 * @approach DFS passing accumulated number, sum at leaves
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto sumNumbers(TreeNode* root) -> int {
        auto dfs = [](this auto&& dfs, TreeNode* node, int currentSum) -> int {
            if (!node) {
                return 0;
            }
            currentSum = currentSum * 10 + node->val;
            if (!node->left && !node->right) {
                return currentSum;
            }
            return dfs(node->left, currentSum) + dfs(node->right, currentSum);
        };
        return dfs(root, 0);
    }
};
