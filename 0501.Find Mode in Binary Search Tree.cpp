/**
 * @brief Inorder traversal to find mode(s) in BST
 * @intuition BST inorder traversal yields sorted values, enabling consecutive duplicate counting
 * @approach Use Morris-like inorder traversal tracking previous node to count consecutive values.
 *           When count exceeds max, clear results and add new mode. When equal to max, add to results.
 * @complexity Time: O(n), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] auto findMode(TreeNode* root) -> vector<int> {
        vector<int> ans;
        TreeNode* prev = nullptr;
        int mx = 0;
        int cnt = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (!node) return;
            dfs(node->left);
            cnt = (prev && prev->val == node->val) ? cnt + 1 : 1;
            if (cnt > mx) {
                ans.clear();
                ans.push_back(node->val);
                mx = cnt;
            } else if (cnt == mx) {
                ans.push_back(node->val);
            }
            prev = node;
            dfs(node->right);
        };
        
        dfs(root);
        return ans;
    }
};
