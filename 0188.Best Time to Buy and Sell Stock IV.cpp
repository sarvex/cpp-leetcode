/**
 * @brief Max profit with at most k transactions using memoized DP
 * @intuition Track state: day, remaining transactions, holding status
 * @approach Top-down DP with memoization for all states
 * @complexity Time: O(n*k), Space: O(n*k)
 */

#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto maxProfit(int k, vector<int>& prices) const -> int {
        const int n = static_cast<int>(prices.size());
        
        // memo[i][j][holding] = max profit from day i with j transactions left
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        
        function<int(int, int, int)> dfs = [&](int day, int txnsLeft, int holding) -> int {
            if (day >= n) {
                return 0;
            }
            if (memo[day][txnsLeft][holding] != -1) {
                return memo[day][txnsLeft][holding];
            }
            
            // Option 1: do nothing
            int result = dfs(day + 1, txnsLeft, holding);
            
            if (holding) {
                // Option 2: sell
                result = std::max(result, prices[day] + dfs(day + 1, txnsLeft, 0));
            } else if (txnsLeft > 0) {
                // Option 2: buy (uses a transaction)
                result = std::max(result, -prices[day] + dfs(day + 1, txnsLeft - 1, 1));
            }
            
            return memo[day][txnsLeft][holding] = result;
        };
        
        return dfs(0, k, 0);
    }
};
