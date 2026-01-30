/**
 * @brief Recursive binary tree inversion
 * @intuition Swap left and right children recursively for all nodes
 * @approach Post-order traversal swapping children after recursive calls
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
  [[nodiscard]] static auto invertTree(TreeNode* root) -> TreeNode* {
    if (root == nullptr) {
      return nullptr;
    }
    auto* left = invertTree(root->left);
    auto* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};
