/**
 * @brief Count ways to assign +/- signs to reach target sum
 * @intuition Transform to subset sum: find subset with sum (total - target) / 2
 * @approach DP: f[i][j] = ways to get sum j using first i elements
 * @complexity Time: O(n * sum), Space: O(n * sum)
 */
#include <cstring>
#include <numeric>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findTargetSumWays(const std::vector<int>& nums, int target) const -> int {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum < target || (sum - target) % 2 != 0) {
            return 0;
        }

        const int m = static_cast<int>(nums.size());
        const int n = (sum - target) / 2;

        std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, 0));
        f[0][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= nums[i - 1]) {
                    f[i][j] += f[i - 1][j - nums[i - 1]];
                }
            }
        }

        return f[m][n];
    }
};
