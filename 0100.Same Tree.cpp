/**
 * @brief Check if two binary trees are structurally identical
 * @intuition Trees are same if roots match and subtrees recursively match
 * @approach Recursive comparison of node values and structure
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static auto isSameTree(TreeNode* p, TreeNode* q) -> bool {
        if (p == q) {
            return true;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
