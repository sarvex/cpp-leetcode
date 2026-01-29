/**
 * @brief Delete node with given key from BST
 * @intuition Replace with inorder successor (leftmost in right subtree)
 * @approach Recursively find node, handle 0/1/2 children cases
 * @complexity Time: O(h) Space: O(h) where h is tree height
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution final {
public:
    [[nodiscard]] auto deleteNode(TreeNode* root, int key) const -> TreeNode* {
        if (!root) {
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (!root->left) {
            return root->right;
        }
        if (!root->right) {
            return root->left;
        }

        TreeNode* node = root->right;
        while (node->left) {
            node = node->left;
        }
        node->left = root->left;

        return root->right;
    }
};
