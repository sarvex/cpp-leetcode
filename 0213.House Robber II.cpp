/**
 * @brief Circular house robber using two linear passes
 * @intuition Houses form a circle, so rob either [0..n-2] or [1..n-1]
 * @approach Run linear house robber twice, take maximum of both
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto rob(const std::vector<int>& nums) -> int {
        const auto n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return std::max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
    [[nodiscard]] static auto robRange(const std::vector<int>& nums, std::size_t left, std::size_t right) -> int {
        int prevPrev = 0;
        int prev = 0;
        for (auto i = left; i <= right; ++i) {
            const int current = std::max(prev, prevPrev + nums[i]);
            prevPrev = prev;
            prev = current;
        }
        return prev;
    }
};
