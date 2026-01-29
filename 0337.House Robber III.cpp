/**
 * @brief Tree DP for maximum robbery without alerting police
 * @intuition At each node, either rob it or skip it
 * @approach DFS returning pair of (rob this node, skip this node)
 * @complexity Time: O(n), Space: O(h) for recursion
 */
#include <algorithm>
#include <functional>
#include <utility>

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
    [[nodiscard]] int rob(TreeNode* root) const {
        std::function<std::pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> std::pair<int, int> {
            if (node == nullptr) {
                return {0, 0};
            }
            auto [leftRob, leftSkip] = dfs(node->left);
            auto [rightRob, rightSkip] = dfs(node->right);
            
            const int robThis = node->val + leftSkip + rightSkip;
            const int skipThis = std::max(leftRob, leftSkip) + std::max(rightRob, rightSkip);
            return {robThis, skipThis};
        };
        
        auto [rob, skip] = dfs(root);
        return std::max(rob, skip);
    }
};
