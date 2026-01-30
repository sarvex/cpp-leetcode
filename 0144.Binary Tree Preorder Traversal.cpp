/**
 * @brief Preorder traversal of binary tree using recursion
 * @intuition Visit root, then left subtree, then right subtree
 * @approach Recursive DFS with preorder visit pattern
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto preorderTraversal(TreeNode* root) -> vector<int> {
        vector<int> result;

        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
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
