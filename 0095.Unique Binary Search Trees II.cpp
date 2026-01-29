/**
 * @brief Generate all structurally unique BSTs with values 1 to n
 * @intuition Each value can be root; recursively build left/right subtrees
 * @approach For each root value, combine all left subtrees with all right subtrees
 * @complexity Time: O(n * Catalan(n)), Space: O(n * Catalan(n))
 */
class Solution final {
public:
    [[nodiscard]] static auto generateTrees(const int n) -> vector<TreeNode*> {
        auto dfs = [&](this auto&& dfs, const int start, const int end) -> vector<TreeNode*> {
            if (start > end) {
                return {nullptr};
            }
            
            vector<TreeNode*> result;
            for (int val = start; val <= end; ++val) {
                auto leftTrees = dfs(start, val - 1);
                auto rightTrees = dfs(val + 1, end);
                
                for (auto* left : leftTrees) {
                    for (auto* right : rightTrees) {
                        result.push_back(new TreeNode(val, left, right));
                    }
                }
            }
            return result;
        };
        
        return dfs(1, n);
    }
};
