/**
 * @brief Tree DP for maximum robbery without alerting police
 * @intuition At each node, either rob it or skip it
 * @approach DFS returning pair of (rob this node, skip this node)
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static int rob(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* node) -> std::pair<int, int> {
            if (node == nullptr) {
                return {0, 0};
            }
            auto [leftRob, leftSkip] = dfs(node->left);
            auto [rightRob, rightSkip] = dfs(node->right);
            
            const int robThis = node->val + leftSkip + rightSkip;
            const int skipThis = std::max(leftRob, leftSkip) + std::max(rightRob, rightSkip);
            return {robThis, skipThis};
        };
        
        auto [robRoot, skipRoot] = dfs(root);
        return std::max(robRoot, skipRoot);
    }
};
