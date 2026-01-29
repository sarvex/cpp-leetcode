/**
 * @brief Find all root-to-leaf paths with target sum
 * @intuition Use backtracking DFS to collect all valid paths
 * @approach Track current path, add to result at matching leaves, backtrack
 * @complexity Time: O(n^2), Space: O(n) for path storage
 */

class Solution final {
public:
    [[nodiscard]] static auto pathSum(TreeNode* root, int targetSum) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        
        auto dfs = [&](this auto&& self, TreeNode* node, int remaining) -> void {
            if (!node) {
                return;
            }
            remaining -= node->val;
            path.emplace_back(node->val);
            
            if (!node->left && !node->right && remaining == 0) {
                result.emplace_back(path);
            }
            
            self(node->left, remaining);
            self(node->right, remaining);
            path.pop_back();
        };
        
        dfs(root, targetSum);
        return result;
    }
};
