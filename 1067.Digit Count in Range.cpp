/**
 * @brief Digit DP counting occurrences of digit d in range
 * @intuition Count digit d in [1, high] minus [1, low-1]
 * @approach Digit DP tracking count of target digit with leading zero handling
 * @complexity Time: O(log n * digits), Space: O(log n * digits)
 */
class Solution final {
public:
    [[nodiscard]] static int digitsCount(const int d, const int low, const int high) {
        auto f = [&](int n) {
            int a[11];
            int dp[11][11];
            memset(dp, -1, sizeof(dp));
            int len = 0;
            while (n) {
                a[++len] = n % 10;
                n /= 10;
            }
            function<int(int, int, bool, bool)> dfs = [&](int pos, int cnt, bool lead, bool limit) -> int {
                if (pos <= 0) {
                    return cnt;
                }
                if (!lead && !limit && dp[pos][cnt] != -1) {
                    return dp[pos][cnt];
                }
                const int up = limit ? a[pos] : 9;
                int ans = 0;
                for (int i = 0; i <= up; ++i) {
                    if (i == 0 && lead) {
                        ans += dfs(pos - 1, cnt, lead, limit && i == up);
                    } else {
                        ans += dfs(pos - 1, cnt + (i == d), false, limit && i == up);
                    }
                }
                if (!lead && !limit) {
                    dp[pos][cnt] = ans;
                }
                return ans;
            };
            return dfs(len, 0, true, true);
        };
        return f(high) - f(low - 1);
    }
};
