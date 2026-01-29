/**
 * @brief Find max path sum in binary tree using post-order DFS
 * @intuition Max path through node = node + max(0, left) + max(0, right)
 * @approach DFS returns max single-branch sum, update global max for paths through node
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <algorithm>
#include <functional>
#include <limits>

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
    [[nodiscard]] auto maxPathSum(TreeNode* root) const -> int {
        int ans = std::numeric_limits<int>::min();
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int leftMax = std::max(0, dfs(node->left));
            const int rightMax = std::max(0, dfs(node->right));
            ans = std::max(ans, leftMax + rightMax + node->val);
            return node->val + std::max(leftMax, rightMax);
        };
        
        dfs(root);
        return ans;
    }
};
