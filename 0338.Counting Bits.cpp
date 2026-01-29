/**
 * @brief Count number of 1 bits for each number from 0 to n
 * @intuition Use built-in popcount for efficient bit counting
 * @approach Iterate and use __builtin_popcount or std::popcount
 * @complexity Time: O(n), Space: O(n) for output
 */
#include <bit>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<int> countBits(int n) const {
        std::vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            ans[i] = std::popcount(static_cast<unsigned>(i));
        }
        return ans;
    }
};
