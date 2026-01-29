/**
 * @brief Find minimum moves to make all elements equal (move = +/-1)
 * @intuition Optimal target is median - minimizes total distance
 * @approach Sort array, sum absolute differences from median
 * @complexity Time: O(n log n) Space: O(1)
 */
#include <algorithm>
#include <cmath>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto minMoves2(std::vector<int>& nums) const -> int {
        std::sort(nums.begin(), nums.end());
        const int k = nums[nums.size() >> 1];

        int ans = 0;
        for (const int v : nums) {
            ans += std::abs(v - k);
        }

        return ans;
    }
};
