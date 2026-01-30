/**
 * @brief Calculate total Hamming distance between all pairs of integers
 * @intuition For each bit position, count pairs with different bits
 * @approach At bit i: if a numbers have 1, b have 0, contribution is a * b
 * @complexity Time: O(32 * n), Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto totalHammingDistance(const std::vector<int>& nums) const -> int {
        int ans = 0;
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (const int x : nums) {
                ones += (x >> i) & 1;
            }
            const int zeros = n - ones;
            ans += ones * zeros;
        }

        return ans;
    }
};
