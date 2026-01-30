/**
 * @brief Convert BST to Greater Tree where each node contains sum of greater values
 * @intuition Reverse inorder (right-root-left) visits nodes in decreasing order
 * @approach Traverse in reverse inorder, maintaining running sum of all visited nodes.
 *           Update each node's value to include running sum, then add original value to sum.
 * @complexity Time: O(n), Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static auto convertBST(TreeNode* root) -> TreeNode* {
        int sum = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (!node) return;
            dfs(node->right);
            sum += node->val;
            node->val = sum;
            dfs(node->left);
        };
        
        dfs(root);
        return root;
    }
};
