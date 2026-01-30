/**
 * @brief Recursive enumeration of all full binary trees with n nodes
 * @intuition Full binary tree with n nodes: root + left subtree + right subtree, odd n only
 * @approach For each valid split (odd left, odd right summing to n-1), recursively
 *           generate all combinations of left and right subtrees.
 * @complexity Time: O(2^n), Space: O(2^n)
 */
class Solution final {
public:
    [[nodiscard]] auto allPossibleFBT(int n) -> std::vector<TreeNode*> {
        std::vector<std::vector<TreeNode*>> memo(n + 1);
        
        auto dfs = [&](auto&& self, int nodes) -> std::vector<TreeNode*> {
            if (!memo[nodes].empty()) return memo[nodes];
            if (nodes == 1) return {new TreeNode()};
            
            std::vector<TreeNode*> ans;
            for (int i = 0; i < nodes - 1; ++i) {
                const int j = nodes - 1 - i;
                for (auto* left : self(self, i)) {
                    for (auto* right : self(self, j)) {
                        ans.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            return memo[nodes] = ans;
        };
        
        return dfs(dfs, n);
    }
};
