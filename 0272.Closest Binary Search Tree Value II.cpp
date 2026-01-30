/**
 * @brief Inorder traversal with sliding window for k closest values
 * @intuition BST inorder gives sorted values, maintain k closest using queue
 * @approach During inorder, keep queue of size k with closest values to target
 * @complexity Time: O(n), Space: O(k)
 */
class Solution final {
public:
  [[nodiscard]] static auto closestKValues(TreeNode* root, const double target, const int k) -> std::vector<int> {
    std::queue<int> q;
    
    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return;
      }
      dfs(node->left);
      if (static_cast<int>(q.size()) < k) {
        q.push(node->val);
      } else {
        if (std::abs(node->val - target) >= std::abs(q.front() - target)) {
          return;
        }
        q.pop();
        q.push(node->val);
      }
      dfs(node->right);
    };
    
    dfs(root);
    
    std::vector<int> result;
    while (!q.empty()) {
      result.push_back(q.front());
      q.pop();
    }
    return result;
  }
};
