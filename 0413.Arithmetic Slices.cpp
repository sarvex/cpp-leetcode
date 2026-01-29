/**
 * @brief Count number of arithmetic slices (subarrays with constant difference)
 * @intuition Each additional element in arithmetic sequence adds cnt+1 new slices
 * @approach Track consecutive elements with same difference, sum contributions
 * @complexity Time: O(n) Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto numberOfArithmeticSlices(const std::vector<int>& nums) const -> int {
        int ans = 0;
        int cnt = 0;
        int d = 3000;

        for (std::size_t i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i + 1] - nums[i] == d) {
                ++cnt;
            } else {
                d = nums[i + 1] - nums[i];
                cnt = 0;
            }
            ans += cnt;
        }

        return ans;
    }
};
