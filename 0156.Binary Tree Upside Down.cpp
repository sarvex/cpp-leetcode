/**
 * @brief Flip binary tree upside down recursively
 * @intuition Left child becomes new root, right sibling becomes left child of new parent
 * @approach Recursive bottom-up transformation rewiring pointers
 * @complexity Time: O(n), Space: O(h) where h is tree height
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
    [[nodiscard]] auto upsideDownBinaryTree(TreeNode* root) const -> TreeNode* {
        if (!root || !root->left) {
            return root;
        }
        
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        root->left->right = root;
        root->left->left = root->right;
        root->left = nullptr;
        root->right = nullptr;
        
        return newRoot;
    }
};
