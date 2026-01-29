/**
 * @brief Check if tree is height-balanced using bottom-up recursion
 * @intuition A tree is balanced if subtrees are balanced and height difference <= 1
 * @approach Return -1 to propagate imbalance, otherwise return actual height
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */

#include <algorithm>
#include <cmath>
#include <functional>

using std::function;

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
    [[nodiscard]] auto isBalanced(TreeNode* root) const -> bool {
        function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int leftHeight = height(node->left);
            const int rightHeight = height(node->right);
            
            if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1) {
                return -1;
            }
            return 1 + std::max(leftHeight, rightHeight);
        };
        
        return height(root) >= 0;
    }
};
