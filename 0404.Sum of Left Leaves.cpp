/**
 * @brief Calculate sum of all left leaves in binary tree
 * @intuition A left leaf is a node with no children that is a left child
 * @approach Recursive traversal, check if left child is a leaf before adding
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static auto sumOfLeftLeaves(TreeNode* root) -> int {
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
