/**
 * @brief Recursive BST search
 * @intuition BST property allows O(log n) search by comparing node values
 * @approach Recursively search left or right subtree based on value comparison
 * @complexity Time: O(h) where h is tree height, Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* searchBST(TreeNode* root, const int val) {
        if (!root || root->val == val) {
            return root;
        }
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
