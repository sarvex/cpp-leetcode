/**
 * @brief Max profit with at most k transactions using memoized DP
 * @intuition Track state: day, remaining transactions, holding status
 * @approach Top-down DP with memoization for all states
 * @complexity Time: O(n*k), Space: O(n*k)
 */

class Solution final {
public:
    [[nodiscard]] static auto maxProfit(int k, std::vector<int>& prices) -> int {
        const int n = static_cast<int>(prices.size());
        
        std::vector<std::vector<std::vector<int>>> memo(
            n, std::vector<std::vector<int>>(k + 1, std::vector<int>(2, -1)));
        
        auto dfs = [&](this auto&& dfs, int day, int txnsLeft, int holding) -> int {
            if (day >= n) {
                return 0;
            }
            if (memo[day][txnsLeft][holding] != -1) {
                return memo[day][txnsLeft][holding];
            }
            
            int result = dfs(day + 1, txnsLeft, holding);
            
            if (holding) {
                result = std::max(result, prices[day] + dfs(day + 1, txnsLeft, 0));
            } else if (txnsLeft > 0) {
                result = std::max(result, -prices[day] + dfs(day + 1, txnsLeft - 1, 1));
            }
            
            return memo[day][txnsLeft][holding] = result;
        };
        
        return dfs(0, k, 0);
    }
};
