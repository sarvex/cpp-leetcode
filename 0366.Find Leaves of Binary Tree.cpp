/**
 * @brief Collect leaves level by level from bottom up
 * @intuition Group nodes by their height (distance to deepest leaf)
 * @approach DFS computing height, group nodes at same height together
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::vector<int>> findLeaves(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            const int l = dfs(node->left);
            const int r = dfs(node->right);
            const int h = std::max(l, r);
            
            if (static_cast<int>(ans.size()) == h) {
                ans.push_back({});
            }
            ans[h].push_back(node->val);
            return h + 1;
        };
        
        dfs(root);
        return ans;
    }
};
