/**
 * @brief Add a row of nodes at specified depth in binary tree
 * @intuition Insert new nodes as parents at target depth, shifting original children down
 * @approach DFS to target depth-1, insert new nodes between parent and children
 * @complexity Time: O(n), Space: O(h) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] TreeNode* addOneRow(TreeNode* root, const int val, const int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        
        auto dfs = [&](this auto&& dfs, TreeNode* node, int d) -> void {
            if (!node) {
                return;
            }
            if (d == depth - 1) {
                auto* l = new TreeNode(val, node->left, nullptr);
                auto* r = new TreeNode(val, nullptr, node->right);
                node->left = l;
                node->right = r;
                return;
            }
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        };
        
        dfs(root, 1);
        return root;
    }
};
