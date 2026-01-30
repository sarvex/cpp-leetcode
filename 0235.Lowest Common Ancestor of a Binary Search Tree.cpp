/**
 * @brief BST property-based LCA search
 * @intuition LCA is first node where p and q are in different subtrees
 * @approach Navigate based on BST property until split point
 * @complexity Time: O(h), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) -> TreeNode* {
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
