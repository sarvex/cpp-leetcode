/**
 * @brief BFS level-by-level traversal of binary tree
 * @intuition Process nodes level by level using a queue
 * @approach Use queue to track nodes at each level, process all nodes at current level before moving to next
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */

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
    [[nodiscard]] auto levelOrder(TreeNode* root) const -> vector<vector<int>> {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> level;
            for (int n = q.size(); n > 0; --n) {
                auto* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(std::move(level));
        }
        return ans;
    }
};
