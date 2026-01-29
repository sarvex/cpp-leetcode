/**
 * @brief Preorder traversal of binary tree using recursion
 * @intuition Visit root, then left subtree, then right subtree
 * @approach Recursive DFS with preorder visit pattern
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
    [[nodiscard]] auto preorderTraversal(TreeNode* root) const -> vector<int> {
        vector<int> result;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            result.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };
        
        dfs(root);
        return result;
    }
};
