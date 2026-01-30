/**
 * @brief DFS accumulating binary value along path
 * @intuition Build binary number while traversing, sum at leaves
 * @approach Pass accumulated value to children, shift and add current bit
 * @complexity Time: O(n), Space: O(h) where h = tree height
 */
class Solution final {
public:
    [[nodiscard]] static int sumRootToLeaf(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* node, int t) -> int {
            if (!node) return 0;
            t = (t << 1) | node->val;
            if (!node->left && !node->right) return t;
            return dfs(node->left, t) + dfs(node->right, t);
        };
        return dfs(root, 0);
    }
};
