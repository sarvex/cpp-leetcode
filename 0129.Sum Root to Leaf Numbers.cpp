/**
 * @brief Sum all root-to-leaf numbers using DFS
 * @intuition Each path forms a number by concatenating node values
 * @approach DFS passing accumulated number, sum at leaves
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <functional>

using std::function;

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
    [[nodiscard]] auto sumNumbers(TreeNode* root) const -> int {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int currentSum) -> int {
            if (!node) {
                return 0;
            }
            currentSum = currentSum * 10 + node->val;
            if (!node->left && !node->right) {
                return currentSum;
            }
            return dfs(node->left, currentSum) + dfs(node->right, currentSum);
        };
        return dfs(root, 0);
    }
};
