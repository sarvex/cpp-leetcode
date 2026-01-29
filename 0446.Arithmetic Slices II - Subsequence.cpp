/**
 * @brief Count arithmetic subsequences of length >= 3
 * @intuition For each pair (i,j), count how many sequences end with this difference
 * @approach DP with hash map at each index tracking counts by difference
 * @complexity Time: O(n^2) Space: O(n^2)
 */
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto numberOfArithmeticSlices(const std::vector<int>& nums) const -> int {
        const int n = static_cast<int>(nums.size());
        std::vector<std::unordered_map<long long, int>> f(n);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                const long long d = 1LL * nums[i] - nums[j];
                const int cnt = f[j][d];
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }

        return ans;
    }
};
