/**
 * @brief Calculate sum of all left leaves in binary tree
 * @intuition A left leaf is a node with no children that is a left child
 * @approach Recursive traversal, check if left child is a leaf before adding
 * @complexity Time: O(n) Space: O(h) where h is tree height
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
    [[nodiscard]] auto sumOfLeftLeaves(TreeNode* root) const -> int {
        if (!root) {
            return 0;
        }

        int ans = sumOfLeftLeaves(root->right);

        if (root->left) {
            if (!root->left->left && !root->left->right) {
                ans += root->left->val;
            } else {
                ans += sumOfLeftLeaves(root->left);
            }
        }

        return ans;
    }
};
