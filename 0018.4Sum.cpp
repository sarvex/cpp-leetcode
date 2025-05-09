
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Four sum using two-pointer technique after sorting.
     *
     * @intuition: Reduce 4Sum to 2Sum by fixing two indices and using two pointers for the rest.
     * @approach: Sort, skip duplicates, use nested loops for first two indices, then two-pointer for the rest.
     * @complexity: Time: O(n^3), Space: O(1) (excluding output)
     */
    [[nodiscard]] std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) const {
        const int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> result;
        if (n < 4) return result;
        std::ranges::sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    const long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[++left - 1]);
                        while (left < right && nums[right] == nums[--right + 1]);
                    }
                }
            }
        }
        return result;
    }
};
