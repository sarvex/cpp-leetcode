/**
 * @brief BFS with alternating direction for zigzag traversal
 * @intuition Level order traversal but reverse alternate levels
 * @approach Use BFS and flip direction flag each level, reverse when needed
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */

#include <algorithm>
#include <queue>
#include <vector>

using std::queue;
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
    [[nodiscard]] auto zigzagLevelOrder(TreeNode* root) const -> vector<vector<int>> {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> q{{root}};
        bool leftToRight = true;
        
        while (!q.empty()) {
            vector<int> level;
            for (int n = q.size(); n > 0; --n) {
                auto* node = q.front();
                q.pop();
                level.emplace_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!leftToRight) {
                std::ranges::reverse(level);
            }
            ans.emplace_back(std::move(level));
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
