/**
 * @brief Recursive tree construction from preorder and postorder
 * @intuition Preorder root comes first; postorder root comes last; find left subtree boundary
 * @approach Root is preorder[0]. Next element in preorder is left subtree root.
 *           Find its position in postorder to determine left subtree size.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] auto constructFromPrePost(const std::vector<int>& preorder,
                                             const std::vector<int>& postorder)
        -> TreeNode* {
        const int n = static_cast<int>(postorder.size());
        std::unordered_map<int, int> pos;
        
        for (int i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        
        auto dfs = [&](auto&& self, int a, int b, int c, int d) -> TreeNode* {
            if (a > b) return nullptr;
            
            auto* root = new TreeNode(preorder[a]);
            if (a == b) return root;
            
            const int i = pos[preorder[a + 1]];
            const int m = i - c + 1;
            root->left = self(self, a + 1, a + m, c, i);
            root->right = self(self, a + m + 1, b, i + 1, d - 1);
            return root;
        };
        
        return dfs(dfs, 0, n - 1, 0, n - 1);
    }
};
