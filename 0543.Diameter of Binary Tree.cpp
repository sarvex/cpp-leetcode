/**
 * @brief DFS to find longest path through any node
 * @intuition The diameter passes through some node as the highest point; track left+right depths
 * @approach For each node, compute max depth of left and right subtrees; diameter is l+r at some node
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            
            const int left = dfs(node->left);
            const int right = dfs(node->right);
            ans = max(ans, left + right);
            
            return 1 + max(left, right);
        };
        
        dfs(root);
        return ans;
    }
};
