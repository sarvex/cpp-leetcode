/**
 * @brief Find minimum absolute difference between any two BST nodes
 * @intuition BST inorder traversal is sorted; min diff must be between consecutive values
 * @approach Inorder traversal tracking previous value. Minimum difference is between
 *           current and previous node values. Update answer at each step.
 * @complexity Time: O(n), Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static auto getMinimumDifference(TreeNode* root) -> int {
        constexpr int INF = 1 << 30;
        int ans = INF;
        int prev = -INF;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (!node) return;
            dfs(node->left);
            ans = min(ans, node->val - prev);
            prev = node->val;
            dfs(node->right);
        };
        
        dfs(root);
        return ans;
    }
};
