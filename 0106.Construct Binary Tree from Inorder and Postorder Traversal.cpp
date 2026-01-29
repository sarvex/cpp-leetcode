/**
 * @brief Build tree using postorder root identification and inorder partitioning
 * @intuition Postorder gives root at end, inorder divides left/right subtrees
 * @approach Use hashmap for O(1) inorder index lookup, recursively build subtrees
 * @complexity Time: O(n), Space: O(n)
 */

#include <functional>
#include <unordered_map>
#include <vector>

using std::function;
using std::unordered_map;
using std::vector;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto buildTree(vector<int>& inorder, vector<int>& postorder) const -> TreeNode* {
        unordered_map<int, int> indexMap;
        const int n = static_cast<int>(inorder.size());
        
        for (int i = 0; i < n; ++i) {
            indexMap[inorder[i]] = i;
        }
        
        function<TreeNode*(int, int, int)> dfs = [&](int inStart, int postStart, int count) -> TreeNode* {
            if (count <= 0) {
                return nullptr;
            }
            const int rootVal = postorder[postStart + count - 1];
            const int inIdx = indexMap[rootVal];
            const int leftCount = inIdx - inStart;
            
            auto* left = dfs(inStart, postStart, leftCount);
            auto* right = dfs(inIdx + 1, postStart + leftCount, count - leftCount - 1);
            return new TreeNode(rootVal, left, right);
        };
        
        return dfs(0, 0, n);
    }
};
