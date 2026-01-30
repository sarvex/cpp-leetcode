/**
 * @brief Find longest path where all nodes have same value
 * @intuition DFS returns longest arm, path through node is sum of left and right arms
 * @approach For each node, compute max extending arm and update global path length
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            int l = dfs(node->left);
            int r = dfs(node->right);
            l = node->left && node->left->val == node->val ? l + 1 : 0;
            r = node->right && node->right->val == node->val ? r + 1 : 0;
            ans = max(ans, l + r);
            return max(l, r);
        };
        
        dfs(root);
        return ans;
    }
};
