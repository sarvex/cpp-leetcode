/**
 * @brief Find all duplicates in array where 1 <= a[i] <= n
 * @intuition Use value as index, swap elements to correct positions
 * @approach Cyclic sort: element x should be at index x-1
 * @complexity Time: O(n) Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findDuplicates(std::vector<int>& nums) const -> std::vector<int> {
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
