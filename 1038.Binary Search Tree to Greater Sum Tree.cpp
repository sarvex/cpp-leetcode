/**
 * @brief Reverse inorder traversal accumulating sums
 * @intuition Reverse inorder visits nodes in decreasing order
 * @approach Visit right, add value to running sum, update node, visit left
 * @complexity Time: O(n), Space: O(h) where h = tree height
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->right);
            s += node->val;
            node->val = s;
            dfs(node->left);
        };
        dfs(root);
        return root;
    }
};
