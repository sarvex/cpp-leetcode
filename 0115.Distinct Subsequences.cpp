/**
 * @brief Count distinct subsequences using 2D DP
 * @intuition DP where f[i][j] = ways to form t[0..j] from s[0..i]
 * @approach If chars match, add both skip and use cases; else just skip
 * @complexity Time: O(m*n), Space: O(m*n)
 */

#include <cstring>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto numDistinct(const string& s, const string& t) const -> int {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(t.size());
        
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return static_cast<int>(dp[m][n]);
    }
};
