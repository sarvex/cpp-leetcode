/**
 * @brief Flip binary tree upside down recursively
 * @intuition Left child becomes new root, right sibling becomes left child of new parent
 * @approach Recursive bottom-up transformation rewiring pointers
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto upsideDownBinaryTree(TreeNode* root) -> TreeNode* {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }
        
        auto* newRoot = upsideDownBinaryTree(root->left);
        root->left->right = root;
        root->left->left = root->right;
        root->left = nullptr;
        root->right = nullptr;
        
        return newRoot;
    }
};
