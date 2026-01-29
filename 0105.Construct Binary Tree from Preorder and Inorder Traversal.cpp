/**
 * @brief Build tree using preorder root identification and inorder partitioning
 * @intuition Preorder gives root, inorder divides left/right subtrees
 * @approach Use hashmap for O(1) inorder index lookup, recursively build subtrees
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto buildTree(const std::vector<int>& preorder, 
                                        const std::vector<int>& inorder) -> TreeNode* {
        const int n = static_cast<int>(preorder.size());
        std::unordered_map<int, int> indexMap;
        
        for (int i = 0; i < n; ++i) {
            indexMap[inorder[i]] = i;
        }
        
        auto dfs = [&](this auto&& self, int preIdx, int inStart, int count) -> TreeNode* {
            if (count <= 0) {
                return nullptr;
            }
            const int rootVal = preorder[preIdx];
            const int inIdx = indexMap[rootVal];
            const int leftCount = inIdx - inStart;
            
            auto* left = self(preIdx + 1, inStart, leftCount);
            auto* right = self(preIdx + 1 + leftCount, inIdx + 1, count - 1 - leftCount);
            return new TreeNode(rootVal, left, right);
        };
        
        return dfs(0, 0, n);
    }
};
