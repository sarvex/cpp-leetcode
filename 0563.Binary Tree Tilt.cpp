/**
 * @brief Sum of absolute differences between left and right subtree sums
 * @intuition Tilt at node = |left_sum - right_sum|; accumulate during traversal
 * @approach DFS returning subtree sum, accumulating tilt as side effect
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static int findTilt(TreeNode* root) {
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            
            const int left = dfs(node->left);
            const int right = dfs(node->right);
            ans += abs(left - right);
            
            return left + right + node->val;
        };
        
        dfs(root);
        return ans;
    }
};
