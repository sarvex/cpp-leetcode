/**
 * @brief Iterative inorder traversal for kth smallest
 * @intuition Inorder traversal of BST visits nodes in sorted order
 * @approach Use stack for iterative inorder, return kth visited node
 * @complexity Time: O(H + k), Space: O(H) where H is tree height
 */

class Solution final {
public:
  [[nodiscard]] static auto kthSmallest(TreeNode* root, int k) -> int {
    std::stack<TreeNode*> stk;
    auto* current = root;
    
    while (current != nullptr || !stk.empty()) {
      if (current != nullptr) {
        stk.push(current);
        current = current->left;
      } else {
        current = stk.top();
        stk.pop();
        if (--k == 0) {
          return current->val;
        }
        current = current->right;
      }
    }
    return 0;
  }
};
