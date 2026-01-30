/**
 * @brief Find inorder successor in BST using BST property
 * @intuition Successor is smallest node greater than p
 * @approach Binary search: track last node where we went left
 * @complexity Time: O(h), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root != nullptr) {
            if (root->val > p->val) {
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
