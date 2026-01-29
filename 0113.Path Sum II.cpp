/**
 * @brief Find all root-to-leaf paths with target sum
 * @intuition Use backtracking DFS to collect all valid paths
 * @approach Track current path, add to result at matching leaves, backtrack
 * @complexity Time: O(n^2), Space: O(n) for path storage
 */

#include <functional>
#include <vector>

using std::function;
using std::vector;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto pathSum(TreeNode* root, int targetSum) const -> vector<vector<int>> {
        vector<vector<int>> ans;
        vector<int> path;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int remaining) {
            if (!node) {
                return;
            }
            remaining -= node->val;
            path.emplace_back(node->val);
            
            if (!node->left && !node->right && remaining == 0) {
                ans.emplace_back(path);
            }
            
            dfs(node->left, remaining);
            dfs(node->right, remaining);
            path.pop_back();
        };
        
        dfs(root, targetSum);
        return ans;
    }
};
