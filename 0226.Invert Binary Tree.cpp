/**
 * @brief Recursive binary tree inversion
 * @intuition Swap left and right children recursively for all nodes
 * @approach Post-order traversal swapping children after recursive calls
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution final {
public:
  [[nodiscard]] auto invertTree(TreeNode* root) const -> TreeNode* {
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
