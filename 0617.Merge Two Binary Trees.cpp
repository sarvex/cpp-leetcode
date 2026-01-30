/**
 * @brief Merge two binary trees by summing overlapping nodes
 * @intuition Recursively merge nodes, summing values where both trees have nodes
 * @approach Create new node with sum of values, recursively merge children
 * @complexity Time: O(min(n, m)), Space: O(min(h1, h2)) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        auto* node = new TreeNode(root1->val + root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};
