/**
 * @brief Determine if array can be partitioned into two equal sum subsets
 * @intuition Find subset with sum = total/2, other subset automatically equal
 * @approach 0/1 knapsack DP with target = total_sum / 2
 * @complexity Time: O(n * sum) Space: O(n * sum)
 */
#include <cstring>
#include <numeric>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto canPartition(std::vector<int>& nums) const -> bool {
        const int s = std::accumulate(nums.begin(), nums.end(), 0);

        if (s % 2 == 1) {
            return false;
        }

        const int n = static_cast<int>(nums.size());
        const int m = s >> 1;

        std::vector<std::vector<bool>> f(n + 1, std::vector<bool>(m + 1, false));
        f[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            const int x = nums[i - 1];
            for (int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
            }
        }

        return f[n][m];
    }
};
