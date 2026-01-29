/**
 * @brief Find minimum transactions to settle debts
 * @intuition Net balances must sum to zero, minimize transfers to settle
 * @approach Bitmask DP on subsets that sum to zero
 * @complexity Time: O(3^n) Space: O(2^n)
 */
#include <cstring>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto minTransfers(std::vector<std::vector<int>>& transactions) const -> int {
        int g[12]{};

        for (const auto& t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }

        std::vector<int> nums;
        for (const int x : g) {
            if (x != 0) {
                nums.push_back(x);
            }
        }

        const int m = static_cast<int>(nums.size());
        std::vector<int> f(1 << m, 0x3f3f3f3f);
        f[0] = 0;

        for (int i = 1; i < (1 << m); ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j) & 1) {
                    s += nums[j];
                }
            }
            if (s == 0) {
                f[i] = __builtin_popcount(i) - 1;
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    f[i] = std::min(f[i], f[j] + f[i ^ j]);
                }
            }
        }

        return f[(1 << m) - 1];
    }
};
