/**
 * @brief Postorder traversal of N-ary tree (children before root)
 * @intuition Visit all children left to right, then add root value
 * @approach DFS: recurse on all children first, then add current value
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> postorder(Node* root) {
        vector<int> ans;
        
        auto dfs = [&](this auto&& dfs, Node* node) -> void {
            if (!node) {
                return;
            }
            for (auto* child : node->children) {
                dfs(child);
            }
            ans.push_back(node->val);
        };
        
        dfs(root);
        return ans;
    }
};
