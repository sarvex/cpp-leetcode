/**
 * @brief Post-order traversal tracking depth to find LCA of deepest nodes
 * @intuition The answer is LCA of all deepest nodes; track depth to identify them
 * @approach Return (node, depth) pairs. If left deeper, return left result; if right
 *           deeper, return right; if equal, current node is LCA of deepest nodes.
 * @complexity Time: O(n), Space: O(h)
 */
class Solution final {
public:
    [[nodiscard]] auto subtreeWithAllDeepest(TreeNode* root) -> TreeNode* {
        auto dfs = [&](auto&& self, TreeNode* node) -> std::pair<TreeNode*, int> {
            if (!node) return {nullptr, 0};
            
            auto [l, ld] = self(self, node->left);
            auto [r, rd] = self(self, node->right);
            
            if (ld > rd) return {l, ld + 1};
            if (ld < rd) return {r, rd + 1};
            return {node, ld + 1};
        };
        
        return dfs(dfs, root).first;
    }
};
