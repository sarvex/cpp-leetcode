/**
 * @brief Find max path sum in binary tree using post-order DFS
 * @intuition Max path through node = node + max(0, left) + max(0, right)
 * @approach DFS returns max single-branch sum, update global max for paths through node
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto maxPathSum(TreeNode* root) -> int {
        int result = std::numeric_limits<int>::min();
        
        auto dfs = [&result](this auto&& self, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int leftMax = std::max(0, self(node->left));
            const int rightMax = std::max(0, self(node->right));
            result = std::max(result, leftMax + rightMax + node->val);
            return node->val + std::max(leftMax, rightMax);
        };
        
        dfs(root);
        return result;
    }
};
