/**
 * @brief Post-order traversal to count univalue subtrees
 * @intuition A subtree is univalue if all nodes have same value
 * @approach DFS checking if subtree is univalue, count valid subtrees
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
#include <functional>

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
  [[nodiscard]] auto countUnivalSubtrees(TreeNode* root) const -> int {
    int count = 0;
    
    std::function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
      if (node == nullptr) {
        return true;
      }
      const bool leftUnivalue = dfs(node->left);
      const bool rightUnivalue = dfs(node->right);
      
      if (!leftUnivalue || !rightUnivalue) {
        return false;
      }
      
      const int leftVal = node->left != nullptr ? node->left->val : node->val;
      const int rightVal = node->right != nullptr ? node->right->val : node->val;
      
      if (leftVal == rightVal && rightVal == node->val) {
        ++count;
        return true;
      }
      return false;
    };
    
    dfs(root);
    return count;
  }
};
