/**
 * @brief Digit DP to count numbers with unique digits
 * @intuition Use bitmask to track used digits during DFS
 * @approach DFS with memoization, handle leading zeros specially
 * @complexity Time: O(n * 2^10), Space: O(n * 2^10)
 */
class Solution final {
public:
    [[nodiscard]] static int countNumbersWithUniqueDigits(const int n) {
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(1 << 10, -1));
        
        auto dfs = [&](this auto&& dfs, int pos, int mask, bool leadingZero) -> int {
            if (pos < 0) {
                return 1;
            }
            if (!leadingZero && memo[pos][mask] != -1) {
                return memo[pos][mask];
            }
            
            int ans = 0;
            for (int digit = 0; digit <= 9; ++digit) {
                if ((mask >> digit) & 1) {
                    continue;
                }
                if (leadingZero && digit == 0) {
                    ans += dfs(pos - 1, mask, true);
                } else {
                    ans += dfs(pos - 1, mask | (1 << digit), false);
                }
            }
            
            if (!leadingZero) {
                memo[pos][mask] = ans;
            }
            return ans;
        };
        
        return dfs(n - 1, 0, true);
    }
};
