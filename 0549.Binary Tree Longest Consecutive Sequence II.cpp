/**
 * @brief DFS tracking both increasing and decreasing paths through each node
 * @intuition Longest path can go up then down (or vice versa) through any node
 * @approach Return pair (incr, decr) from each node; combine children paths at parent
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static int longestConsecutive(TreeNode* root) {
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, int> {
            if (!node) {
                return {0, 0};
            }
            
            int incr = 1, decr = 1;
            auto [leftIncr, leftDecr] = dfs(node->left);
            auto [rightIncr, rightDecr] = dfs(node->right);
            
            if (node->left) {
                if (node->left->val + 1 == node->val) {
                    incr = leftIncr + 1;
                }
                if (node->left->val - 1 == node->val) {
                    decr = leftDecr + 1;
                }
            }
            
            if (node->right) {
                if (node->right->val + 1 == node->val) {
                    incr = max(incr, rightIncr + 1);
                }
                if (node->right->val - 1 == node->val) {
                    decr = max(decr, rightDecr + 1);
                }
            }
            
            ans = max(ans, incr + decr - 1);
            return {incr, decr};
        };
        
        dfs(root);
        return ans;
    }
};
