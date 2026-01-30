/**
 * @brief Trim BST to values within [low, high] range
 * @intuition BST property allows pruning entire subtrees
 * @approach If node < low, only right subtree may have valid nodes; similar for > high
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* trimBST(TreeNode* root, const int low, const int high) {
        if (!root) {
            return root;
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
