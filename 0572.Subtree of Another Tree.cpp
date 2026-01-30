/**
 * @brief Check if subRoot is structurally identical subtree of root
 * @intuition Either root matches subRoot exactly, or recurse into children
 * @approach Use helper to check tree equality; main function tries all subtrees
 * @complexity Time: O(m*n), Space: O(h) where h is height of root
 */
class Solution final {
public:
    [[nodiscard]] static bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        return isSameTree(root, subRoot) || 
               isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }

private:
    [[nodiscard]] static bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && 
               isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
