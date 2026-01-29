/**
 * @brief Recursive mirror comparison for tree symmetry
 * @intuition A tree is symmetric if left and right subtrees are mirror images
 * @approach Use recursive DFS comparing left-right pairs as mirrors
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static auto isSymmetric(TreeNode* root) -> bool {
        auto dfs = [&](this auto&& dfs, TreeNode* left, TreeNode* right) -> bool {
            if (left == right) {
                return true;
            }
            if (left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            return dfs(left->left, right->right) && dfs(left->right, right->left);
        };
        
        return dfs(root->left, root->right);
    }
};
