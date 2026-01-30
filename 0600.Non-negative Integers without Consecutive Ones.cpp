/**
 * @brief Digit DP to count integers without consecutive ones
 * @intuition Use digit DP with memoization to count valid binary representations
 * @approach Process bits from high to low, tracking previous bit to avoid consecutive ones
 * @complexity Time: O(log n), Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static int findIntegers(const int n) {
        const int m = 32 - __builtin_clz(n);
        int f[m][2];
        memset(f, -1, sizeof(f));
        
        auto dfs = [&](this auto&& dfs, int i, int pre, bool limit) -> int {
            if (i < 0) {
                return 1;
            }
            if (!limit && f[i][pre] != -1) {
                return f[i][pre];
            }
            const int up = limit ? (n >> i & 1) : 1;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j && pre) {
                    continue;
                }
                ans += dfs(i - 1, j, limit && j == up);
            }
            if (!limit) {
                f[i][pre] = ans;
            }
            return ans;
        };
        
        return dfs(m - 1, 0, true);
    }
};
