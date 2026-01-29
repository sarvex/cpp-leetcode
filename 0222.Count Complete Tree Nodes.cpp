/**
 * @brief Recursive node counting for complete binary tree
 * @intuition Each node contributes 1 plus the count of its subtrees
 * @approach Simple recursive traversal summing all nodes
 * @complexity Time: O(n), Space: O(log n) for recursion stack
 */

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
  [[nodiscard]] auto countNodes(const TreeNode* root) const -> int {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
