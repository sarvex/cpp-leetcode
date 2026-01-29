/**
 * @brief Recursive mirror comparison for tree symmetry
 * @intuition A tree is symmetric if its left and right subtrees are mirror images
 * @approach Use recursive DFS comparing left-right pairs as mirrors
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
    [[nodiscard]] auto isSymmetric(TreeNode* root) const -> bool {
        auto dfs = [&](this auto&& dfs, TreeNode* root1, TreeNode* root2) -> bool {
            if (root1 == root2) {
                return true;
            }
            if (!root1 || !root2 || root1->val != root2->val) {
                return false;
            }
            return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        };
        return dfs(root->left, root->right);
    }
};
