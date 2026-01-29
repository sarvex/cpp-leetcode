/**
 * @brief Recursive inorder traversal of binary tree
 * @intuition Inorder visits left subtree, root, then right subtree
 * @approach DFS recursively traversing left, collecting value, then right
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static auto inorderTraversal(TreeNode* root) -> vector<int> {
        vector<int> result;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            dfs(node->left);
            result.push_back(node->val);
            dfs(node->right);
        };
        
        dfs(root);
        return result;
    }
};
