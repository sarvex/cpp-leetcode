/**
 * @brief Find minimum cuts for palindrome partitioning using DP
 * @intuition Precompute palindromes, then DP for minimum cuts ending at each position
 * @approach Two DP arrays: one for palindrome check, one for min cuts
 * @complexity Time: O(n^2), Space: O(n^2)
 */

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto minCut(const string& s) const -> int {
        const int n = static_cast<int>(s.size());
        
        // Precompute palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                isPalin[i][j] = (s[i] == s[j]) && isPalin[i + 1][j - 1];
            }
        }
        
        // DP for minimum cuts
        vector<int> dp(n);
        std::iota(dp.begin(), dp.end(), 0);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (isPalin[j][i]) {
                    dp[i] = std::min(dp[i], j > 0 ? 1 + dp[j - 1] : 0);
                }
            }
        }
        
        return dp[n - 1];
    }
};
