/**
 * @brief Preorder traversal of N-ary tree (root before children)
 * @intuition Visit root first, then recursively visit each child left to right
 * @approach DFS: add current value, then recurse on all children
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> preorder(Node* root) {
        vector<int> ans;
        
        auto dfs = [&](this auto&& dfs, Node* node) -> void {
            if (!node) {
                return;
            }
            ans.push_back(node->val);
            for (auto* child : node->children) {
                dfs(child);
            }
        };
        
        dfs(root);
        return ans;
    }
};
