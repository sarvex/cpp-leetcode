/**
 * @brief Recursive node counting for complete binary tree
 * @intuition Each node contributes 1 plus the count of its subtrees
 * @approach Simple recursive traversal summing all nodes
 * @complexity Time: O(n), Space: O(log n) for recursion stack
 */

class Solution final {
public:
  [[nodiscard]] static auto countNodes(const TreeNode* root) -> int {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
