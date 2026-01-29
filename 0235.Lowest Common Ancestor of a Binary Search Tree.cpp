/**
 * @brief BST property-based LCA search
 * @intuition LCA is first node where p and q are in different subtrees
 * @approach Navigate based on BST property until split point
 * @complexity Time: O(h), Space: O(1)
 */
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution final {
public:
  [[nodiscard]] auto lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) const -> TreeNode* {
    while (root != nullptr) {
      if (root->val < std::min(p->val, q->val)) {
        root = root->right;
      } else if (root->val > std::max(p->val, q->val)) {
        root = root->left;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};
