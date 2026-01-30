/**
 * @brief Count subarrays with max element in [left, right]
 * @intuition Count subarrays with max <= right minus those with max < left
 * @approach Inclusion-exclusion: f(right) - f(left-1) where f counts max <= x
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int numSubarrayBoundedMax(const std::vector<int>& nums,
                                                    const int left, const int right) {
        auto countAtMost = [&](const int maxVal) -> int {
            int count = 0;
            int runningLength = 0;
            for (const int num : nums) {
                runningLength = (num > maxVal) ? 0 : runningLength + 1;
                count += runningLength;
            }
            return count;
        };
        return countAtMost(right) - countAtMost(left - 1);
    }
};
