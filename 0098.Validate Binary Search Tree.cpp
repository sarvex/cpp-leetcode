/**
 * @brief Validate BST using inorder traversal
 * @intuition Inorder traversal of valid BST produces strictly increasing sequence
 * @approach DFS inorder tracking previous node; validate current > previous
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static auto isValidBST(TreeNode* root) -> bool {
        TreeNode* prev = nullptr;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> bool {
            if (node == nullptr) {
                return true;
            }
            if (!dfs(node->left)) {
                return false;
            }
            if (prev != nullptr && prev->val >= node->val) {
                return false;
            }
            prev = node;
            return dfs(node->right);
        };
        
        return dfs(root);
    }
};
