/**
 * @brief Split array into k subarrays to minimize largest sum
 * @intuition Binary search on answer - if max sum is x, greedily count subarrays needed
 * @approach Binary search between max element and total sum, validate with greedy check
 * @complexity Time: O(n log(sum)) Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto splitArray(std::vector<int>& nums, int k) const -> int {
        int left = 0;
        int right = 0;

        for (const int x : nums) {
            left = std::max(left, x);
            right += x;
        }

        auto check = [&](int mx) {
            int s = 1 << 30;
            int cnt = 0;
            for (const int x : nums) {
                s += x;
                if (s > mx) {
                    s = x;
                    ++cnt;
                }
            }
            return cnt <= k;
        };

        while (left < right) {
            const int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
