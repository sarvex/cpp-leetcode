/**
 * @brief Flatten BST to right-skewed tree in sorted order
 * @intuition In-order traversal gives sorted order; relink as we traverse
 * @approach Use in-order traversal. Maintain previous node pointer. For each
 *           visited node, set prev->right = current, current->left = null.
 * @complexity Time: O(n), Space: O(h)
 */
class Solution final {
public:
    [[nodiscard]] auto increasingBST(TreeNode* root) -> TreeNode* {
        auto* dummy = new TreeNode(0, nullptr, root);
        auto* prev = dummy;
        
        auto dfs = [&](auto&& self, TreeNode* node) -> void {
            if (!node) return;
            self(self, node->left);
            prev->right = node;
            node->left = nullptr;
            prev = node;
            self(self, node->right);
        };
        
        dfs(dfs, root);
        return dummy->right;
    }
};
