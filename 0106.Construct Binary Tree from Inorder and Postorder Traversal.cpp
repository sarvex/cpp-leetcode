/**
 * @brief Build tree using postorder root identification and inorder partitioning
 * @intuition Postorder gives root at end, inorder divides left/right subtrees
 * @approach Use hashmap for O(1) inorder index lookup, recursively build subtrees
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto buildTree(const std::vector<int>& inorder, 
                                        const std::vector<int>& postorder) -> TreeNode* {
        std::unordered_map<int, int> indexMap;
        const int n = static_cast<int>(inorder.size());
        
        for (int i = 0; i < n; ++i) {
            indexMap[inorder[i]] = i;
        }
        
        auto dfs = [&](this auto&& self, int inStart, int postStart, int count) -> TreeNode* {
            if (count <= 0) {
                return nullptr;
            }
            const int rootVal = postorder[postStart + count - 1];
            const int inIdx = indexMap[rootVal];
            const int leftCount = inIdx - inStart;
            
            auto* left = self(inStart, postStart, leftCount);
            auto* right = self(inIdx + 1, postStart + leftCount, count - leftCount - 1);
            return new TreeNode(rootVal, left, right);
        };
        
        return dfs(0, 0, n);
    }
};
