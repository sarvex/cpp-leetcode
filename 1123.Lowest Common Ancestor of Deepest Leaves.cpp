/**
 * @brief Find LCA of deepest leaves using DFS with depth tracking
 * @intuition Return the node where left and right subtrees have equal maximum depth
 * @approach Use DFS returning (node, depth) pairs. If left is deeper, return left result.
 *           If right is deeper, return right result. If equal, current node is the LCA.
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<TreeNode*, int> {
            if (!root) {
                return {nullptr, 0};
            }
            auto [l, d1] = dfs(root->left);
            auto [r, d2] = dfs(root->right);
            if (d1 > d2) {
                return {l, d1 + 1};
            }
            if (d1 < d2) {
                return {r, d2 + 1};
            }
            return {root, d1 + 1};
        };
        return dfs(root).first;
    }
};
