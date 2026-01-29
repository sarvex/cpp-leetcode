/**
 * @brief Postorder traversal of binary tree using recursion
 * @intuition Visit left subtree, right subtree, then root
 * @approach Recursive DFS with postorder visit pattern
 * @complexity Time: O(n), Space: O(h) where h is tree height
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
    [[nodiscard]] auto postorderTraversal(TreeNode* root) const -> vector<int> {
        vector<int> result;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            dfs(node->right);
            result.push_back(node->val);
        };
        
        dfs(root);
        return result;
    }
};
