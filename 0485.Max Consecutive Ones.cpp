/**
 * @brief Find maximum consecutive 1s in binary array
 * @intuition Track current streak, reset on 0, update max
 * @approach Single pass counting consecutive ones
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findMaxConsecutiveOnes(const std::vector<int>& nums) const -> int {
        int ans = 0;
        int cnt = 0;

        for (const int x : nums) {
            if (x == 1) {
                ans = std::max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
};
