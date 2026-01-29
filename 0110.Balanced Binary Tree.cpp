/**
 * @brief Check if tree is height-balanced using bottom-up recursion
 * @intuition A tree is balanced if subtrees are balanced and height difference <= 1
 * @approach Return -1 to propagate imbalance, otherwise return actual height
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

class Solution final {
public:
    [[nodiscard]] static auto isBalanced(const TreeNode* root) -> bool {
        auto height = [](this auto&& self, const TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int leftHeight = self(node->left);
            const int rightHeight = self(node->right);
            
            if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1) {
                return -1;
            }
            return 1 + std::max(leftHeight, rightHeight);
        };
        
        return height(root) >= 0;
    }
};
