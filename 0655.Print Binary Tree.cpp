/**
 * @brief Print binary tree in 2D grid format
 * @intuition Grid dimensions depend on tree height, nodes placed at specific positions
 * @approach Calculate height, create grid, DFS to place node values at correct positions
 * @complexity Time: O(n), Space: O(n * 2^h) for output grid
 */
class Solution final {
public:
    [[nodiscard]] vector<vector<string>> printTree(TreeNode* root) {
        auto height = [](this auto&& height, TreeNode* node) -> int {
            if (!node) {
                return -1;
            }
            return 1 + max(height(node->left), height(node->right));
        };
        
        const int h = height(root);
        const int m = h + 1;
        const int n = (1 << (h + 1)) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        
        auto dfs = [&](this auto&& dfs, TreeNode* node, int row, int col) -> void {
            if (!node) {
                return;
            }
            ans[row][col] = to_string(node->val);
            const int offset = 1 << (h - row - 1);
            dfs(node->left, row + 1, col - offset);
            dfs(node->right, row + 1, col + offset);
        };
        
        dfs(root, 0, (n - 1) / 2);
        return ans;
    }
};
