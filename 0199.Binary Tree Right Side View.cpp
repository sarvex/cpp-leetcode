/**
 * @brief Get rightmost node at each level using BFS
 * @intuition Level order traversal, first node at each level (processing right first)
 * @approach BFS prioritizing right children, capture first node of each level
 * @complexity Time: O(n), Space: O(w) where w is max width
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
    [[nodiscard]] auto rightSideView(TreeNode* root) const -> vector<int> {
        vector<int> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            result.push_back(q.front()->val);  // First node is rightmost
            
            for (int k = q.size(); k > 0; --k) {
                auto* node = q.front();
                q.pop();
                
                // Process right first to have rightmost at front
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
            }
        }
        
        return result;
    }
};
