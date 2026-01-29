/**
 * @brief Recursive LCA for binary tree
 * @intuition LCA is where p and q are in different subtrees, or node is p/q
 * @approach Post-order traversal returning found node or nullptr
 * @complexity Time: O(n), Space: O(h)
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution final {
public:
  [[nodiscard]] auto lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) const -> TreeNode* {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    auto* left = lowestCommonAncestor(root->left, p, q);
    auto* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
      return root;
    }
    return left != nullptr ? left : right;
  }
};
