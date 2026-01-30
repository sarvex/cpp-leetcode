/**
 * @brief Digit DP counting numbers with all unique digits
 * @intuition Count numbers without repeated digits, subtract from n
 * @approach Digit DP with bitmask tracking used digits, handle leading zeros
 * @complexity Time: O(log n * 2^10 * 10), Space: O(log n * 2^10)
 */
class Solution final {
public:
    [[nodiscard]] static int numDupDigitsAtMostN(const int n) {
        string s = to_string(n);
        const int m = s.size();
        int f[m][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!lead && !limit && f[i][mask] != -1) {
                return f[i][mask];
            }
            const int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else if ((mask >> j & 1) ^ 1) {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return n - dfs(0, 0, true, true);
    }
};
