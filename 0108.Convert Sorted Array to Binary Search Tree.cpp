/**
 * @brief Build height-balanced BST from sorted array
 * @intuition Middle element becomes root, recursively build left and right subtrees
 * @approach Binary search style recursion selecting middle as root each time
 * @complexity Time: O(n), Space: O(log n) for recursion stack
 */

#include <vector>

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
    [[nodiscard]] auto sortedArrayToBST(vector<int>& nums) const -> TreeNode* {
        auto dfs = [&](this auto&& dfs, int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }
            const int mid = left + (right - left) / 2;
            return new TreeNode(nums[mid], dfs(left, mid - 1), dfs(mid + 1, right));
        };
        return dfs(0, static_cast<int>(nums.size()) - 1);
    }
};
