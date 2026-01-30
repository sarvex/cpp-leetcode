/**
 * @brief Determine if second player can win by blocking first player's expansion
 * @intuition Second player should choose adjacent node that gives access to most nodes
 * @approach Find node x and count nodes in its left subtree, right subtree, and parent's side.
 *           Second player wins if any of these three regions has more than half the nodes.
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static bool btreeGameWinningMove(TreeNode* root, const int n, const int x) {
        auto findNode = [](this auto&& findNode, TreeNode* root, int x) -> TreeNode* {
            if (!root || root->val == x) {
                return root;
            }
            auto node = findNode(root->left, x);
            return node ? node : findNode(root->right, x);
        };
        auto countNodes = [](this auto&& countNodes, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
        };
        auto node = findNode(root, x);
        int l = countNodes(node->left), r = countNodes(node->right);
        return max({l, r, n - l - r - 1}) > n / 2;
    }
};
