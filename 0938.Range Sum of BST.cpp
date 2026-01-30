/**
 * @brief Sum BST nodes within given range using DFS
 * @intuition Prune branches outside range using BST property
 * @approach DFS with early termination when node value outside range
 * @complexity Time: O(n), Space: O(h)
 */
class Solution final {
public:
    [[nodiscard]] static int rangeSumBST(TreeNode* root, const int low, const int high) {
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int x = node->val;
            int ans = (low <= x && x <= high) ? x : 0;
            if (x > low) {
                ans += dfs(node->left);
            }
            if (x < high) {
                ans += dfs(node->right);
            }
            return ans;
        };
        return dfs(root);
    }
};
