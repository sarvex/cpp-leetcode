/**
 * @brief Recursive post-order pruning of binary tree
 * @intuition Prune subtrees that don't contain 1; process children before parent
 * @approach Post-order traversal: recursively prune left and right subtrees,
 *           then check if current node should be pruned (value 0 with no children).
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] auto pruneTree(TreeNode* root) -> TreeNode* {
        if (!root) return nullptr;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if (root->val == 0 && !root->left && !root->right) {
            return nullptr;
        }
        return root;
    }
};
