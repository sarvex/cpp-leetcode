/**
 * @brief Find max subset size where total 0s <= m and 1s <= n
 * @intuition 0/1 knapsack with two constraints (0s and 1s count)
 * @approach DP: f[i][j][k] = max subset from first i strings with j 0s and k 1s
 * @complexity Time: O(l * m * n), Space: O(l * m * n)
 */
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findMaxForm(const std::vector<std::string>& strs, int m, int n) const -> int {
        const int sz = static_cast<int>(strs.size());
        std::vector<std::vector<std::vector<int>>> f(sz + 1,
            std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));

        for (int i = 1; i <= sz; ++i) {
            auto [zeros, ones] = countZerosOnes(strs[i - 1]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= zeros && k >= ones) {
                        f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }

        return f[sz][m][n];
    }

private:
    [[nodiscard]] static auto countZerosOnes(const std::string& s) -> std::pair<int, int> {
        int zeros = 0;
        for (const char c : s) {
            if (c == '0') {
                ++zeros;
            }
        }
        return {zeros, static_cast<int>(s.size()) - zeros};
    }
};
