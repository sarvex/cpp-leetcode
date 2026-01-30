/**
 * @brief Find maximum average value among all subtrees
 * @intuition Use post-order DFS to compute sum and count for each subtree, tracking max average
 * @approach For each node, recursively get sum and count of left and right subtrees. Compute
 *           current subtree's average and update maximum. Return sum and count for parent computation.
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }
            auto [ls, ln] = dfs(root->left);
            auto [rs, rn] = dfs(root->right);
            int s = root->val + ls + rs;
            int n = 1 + ln + rn;
            ans = max(ans, s * 1.0 / n);
            return {s, n};
        };
        dfs(root);
        return ans;
    }
};
