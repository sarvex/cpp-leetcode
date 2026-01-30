/**
 * @brief Find max consecutive 1s if you can flip at most one 0
 * @intuition Sliding window allowing at most one 0
 * @approach Track count of zeros in window, shrink when count exceeds 1
 * @complexity Time: O(n), Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findMaxConsecutiveOnes(const std::vector<int>& nums) const -> int {
        int left = 0;
        int zeroCount = 0;

        for (const int x : nums) {
            zeroCount += x ^ 1;
            if (zeroCount > 1) {
                zeroCount -= nums[left++] ^ 1;
            }
        }

        return static_cast<int>(nums.size()) - left;
    }
};
