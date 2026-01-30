/**
 * @brief Recursive BST insertion
 * @intuition BST property guides insertion to maintain sorted order
 * @approach Recursively traverse to find null position and create new node
 * @complexity Time: O(h) where h is tree height, Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* insertIntoBST(TreeNode* root, const int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
