/**
 * @brief Convert binary tree to string with parentheses
 * @intuition Preorder traversal with parentheses for non-null children
 * @approach Recursively build string, omitting empty right parentheses when possible
 * @complexity Time: O(n), Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static string tree2str(TreeNode* root) {
        if (!root) {
            return "";
        }
        if (!root->left && !root->right) {
            return to_string(root->val);
        }
        if (!root->right) {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};
