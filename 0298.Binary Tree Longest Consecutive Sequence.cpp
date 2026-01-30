/**
 * @brief DFS to find longest consecutive sequence in binary tree
 * @intuition Track consecutive length at each node, reset if not consecutive
 * @approach Post-order DFS, extend sequence if child val equals parent val + 1
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static int longestConsecutive(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int left = dfs(node->left) + 1;
            int right = dfs(node->right) + 1;
            
            if (node->left != nullptr && node->left->val - node->val != 1) {
                left = 1;
            }
            if (node->right != nullptr && node->right->val - node->val != 1) {
                right = 1;
            }
            
            const int maxLen = max(left, right);
            ans = max(ans, maxLen);
            return maxLen;
        };
        
        dfs(root);
        return ans;
    }
};
