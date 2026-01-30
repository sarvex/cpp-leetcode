/**
 * @brief Check if two nodes in BST sum to target k
 * @intuition Use hash set to track seen values while traversing
 * @approach DFS with hash set, check if complement exists for each node
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool findTarget(TreeNode* root, const int k) {
        unordered_set<int> vis;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> bool {
            if (!node) {
                return false;
            }
            if (vis.count(k - node->val)) {
                return true;
            }
            vis.insert(node->val);
            return dfs(node->left) || dfs(node->right);
        };
        
        return dfs(root);
    }
};
