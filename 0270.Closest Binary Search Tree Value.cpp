/**
 * @brief Binary search in BST for closest value
 * @intuition Navigate BST toward target, tracking closest value seen
 * @approach Use BST property to guide search direction
 * @complexity Time: O(h), Space: O(1)
 */
#include <cmath>
#include <climits>
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
  [[nodiscard]] auto closestValue(TreeNode* root, double target) const -> int {
    int closest = root->val;
    double minDiff = INT_MAX;
    
    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return;
      }
      const double diff = std::abs(node->val - target);
      if (diff < minDiff || (diff == minDiff && node->val < closest)) {
        minDiff = diff;
        closest = node->val;
      }
      dfs(target < node->val ? node->left : node->right);
    };
    
    dfs(root);
    return closest;
  }
};
