/**
 * @brief Recover BST by finding and swapping two misplaced nodes
 * @intuition Inorder traversal reveals violations where prev > current
 * @approach Track first and second violations during inorder; swap their values
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    static auto recoverTree(TreeNode* root) -> void {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            dfs(node->left);
            
            if (prev != nullptr && prev->val > node->val) {
                if (first == nullptr) {
                    first = prev;
                }
                second = node;
            }
            prev = node;
            
            dfs(node->right);
        };
        
        dfs(root);
        swap(first->val, second->val);
    }
};
