/**
 * @brief DFS to find all root-to-leaf paths
 * @intuition Traverse tree, build path string, add to result at leaves
 * @approach Backtracking with path construction
 * @complexity Time: O(n^2), Space: O(n) for recursion and path storage
 */
class Solution final {
private:
  [[nodiscard]] static auto joinPath(const std::vector<std::string>& parts) -> std::string {
    std::string result;
    for (std::size_t i = 0; i < parts.size(); ++i) {
      if (i > 0) {
        result += "->";
      }
      result += parts[i];
    }
    return result;
  }

public:
  [[nodiscard]] static auto binaryTreePaths(TreeNode* root) -> std::vector<std::string> {
    std::vector<std::string> result;
    std::vector<std::string> path;
    
    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return;
      }
      path.push_back(std::to_string(node->val));
      if (node->left == nullptr && node->right == nullptr) {
        result.push_back(joinPath(path));
      } else {
        dfs(node->left);
        dfs(node->right);
      }
      path.pop_back();
    };
    
    dfs(root);
    return result;
  }
};
