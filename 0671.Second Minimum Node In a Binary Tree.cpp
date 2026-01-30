/**
 * @brief Find second minimum value in special binary tree
 * @intuition Root has minimum value; find smallest value strictly greater than root
 * @approach DFS tracking smallest value greater than root value
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        const int rootVal = root->val;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (!node) {
                return;
            }
            dfs(node->left);
            dfs(node->right);
            if (node->val > rootVal) {
                ans = ans == -1 ? node->val : min(ans, node->val);
            }
        };
        
        dfs(root);
        return ans;
    }
};
