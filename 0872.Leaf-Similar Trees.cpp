/**
 * @brief Compare leaf sequences of two binary trees
 * @intuition Trees are leaf-similar if leaf value sequences match
 * @approach DFS both trees, collecting leaf values in order. Compare the
 *           resulting sequences for equality.
 * @complexity Time: O(n1 + n2), Space: O(n1 + n2)
 */
class Solution final {
    static auto collectLeaves(TreeNode* root, std::vector<int>& leaves) -> void {
        if (root->left == root->right) {
            leaves.push_back(root->val);
            return;
        }
        if (root->left) collectLeaves(root->left, leaves);
        if (root->right) collectLeaves(root->right, leaves);
    }

public:
    [[nodiscard]] static auto leafSimilar(TreeNode* root1, TreeNode* root2) -> bool {
        std::vector<int> l1, l2;
        collectLeaves(root1, l1);
        collectLeaves(root2, l2);
        return l1 == l2;
    }
};
