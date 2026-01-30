/**
 * @brief Post-order DFS to delete nodes and collect remaining roots
 * @intuition Process children before parent so we can properly detach and collect subtree roots
 * @approach Use post-order DFS. After processing children, if current node should be deleted,
 *           add its non-null children to result and return nullptr. Otherwise return the node.
 * @complexity Time: O(n), Space: O(n) for recursion and result
 */
class Solution final {
public:
    [[nodiscard]] static vector<TreeNode*> delNodes(TreeNode* root, const vector<int>& to_delete) {
        vector<bool> s(1001, false);
        for (int x : to_delete) {
            s[x] = true;
        }
        vector<TreeNode*> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> TreeNode* {
            if (!root) {
                return nullptr;
            }
            root->left = dfs(root->left);
            root->right = dfs(root->right);
            if (!s[root->val]) {
                return root;
            }
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        };
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};
