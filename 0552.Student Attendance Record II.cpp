/**
 * @brief Count valid attendance records using memoized DP
 * @intuition State: position, absence count, consecutive late count
 * @approach DFS with memo tracking (day, absences, consecutive_lates); try P, A (if <1), L (if <2)
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int checkRecord(const int n) {
        int memo[n][2][3];
        memset(memo, -1, sizeof(memo));
        constexpr int mod = 1e9 + 7;
        
        auto dfs = [&](this auto&& dfs, int i, int absences, int lates) -> int {
            if (i >= n) {
                return 1;
            }
            if (memo[i][absences][lates] != -1) {
                return memo[i][absences][lates];
            }
            
            int ans = dfs(i + 1, absences, 0);
            if (absences == 0) {
                ans = (ans + dfs(i + 1, absences + 1, 0)) % mod;
            }
            if (lates < 2) {
                ans = (ans + dfs(i + 1, absences, lates + 1)) % mod;
            }
            
            return memo[i][absences][lates] = ans;
        };
        
        return dfs(0, 0, 0);
    }
};
