/**
 * @brief Build height-balanced BST from sorted array
 * @intuition Middle element becomes root, recursively build left and right subtrees
 * @approach Binary search style recursion selecting middle as root each time
 * @complexity Time: O(n), Space: O(log n) for recursion stack
 */

class Solution final {
public:
    [[nodiscard]] static auto sortedArrayToBST(const std::vector<int>& nums) -> TreeNode* {
        auto dfs = [&](this auto&& self, int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }
            const int mid = left + (right - left) / 2;
            return new TreeNode(nums[mid], self(left, mid - 1), self(mid + 1, right));
        };
        return dfs(0, static_cast<int>(nums.size()) - 1);
    }
};
