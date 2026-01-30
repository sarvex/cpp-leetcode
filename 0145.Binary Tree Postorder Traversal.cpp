/**
 * @brief Postorder traversal of binary tree using recursion
 * @intuition Visit left subtree, right subtree, then root
 * @approach Recursive DFS with postorder visit pattern
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto postorderTraversal(TreeNode* root) -> vector<int> {
        vector<int> result;

        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
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
