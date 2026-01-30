/**
 * @brief Find all duplicate subtrees in binary tree
 * @intuition Serialize subtrees and use hashmap to count occurrences
 * @approach DFS serialization with counting, return nodes seen exactly twice
 * @complexity Time: O(n^2), Space: O(n^2) for serialization
 */
class Solution final {
public:
    [[nodiscard]] vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> counter;
        vector<TreeNode*> ans;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> string {
            if (!node) {
                return "#";
            }
            string v = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
            if (++counter[v] == 2) {
                ans.push_back(node);
            }
            return v;
        };
        
        dfs(root);
        return ans;
    }
};
