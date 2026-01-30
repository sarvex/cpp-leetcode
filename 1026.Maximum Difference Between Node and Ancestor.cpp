/**
 * @brief DFS tracking min/max ancestors
 * @intuition Max difference involves path extremes; track min/max along each path
 * @approach Pass down min/max values, compute differences at each node
 * @complexity Time: O(n), Space: O(h) where h = tree height
 */
class Solution final {
public:
    [[nodiscard]] static int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int mi, int mx) {
            if (!node) {
                return;
            }
            ans = max({ans, abs(mi - node->val), abs(mx - node->val)});
            mi = min(mi, node->val);
            mx = max(mx, node->val);
            dfs(node->left, mi, mx);
            dfs(node->right, mi, mx);
        };
        dfs(root, root->val, root->val);
        return ans;
    }
};
