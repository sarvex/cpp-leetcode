/**
 * @brief Stock trading with transaction fee using memoized DFS
 * @intuition Track holding state; fee paid on sell
 * @approach Memoized recursion with state (index, holding), transition on buy/sell/skip
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxProfit(const std::vector<int>& prices, const int fee) {
        const int n = static_cast<int>(prices.size());
        std::vector<std::array<int, 2>> memo(n, {-1, -1});
        
        auto dfs = [&](auto&& self, const int i, const int holding) -> int {
            if (i >= n) {
                return 0;
            }
            if (memo[i][holding] != -1) {
                return memo[i][holding];
            }
            int result = self(self, i + 1, holding);
            if (holding) {
                result = std::max(result, prices[i] + self(self, i + 1, 0) - fee);
            } else {
                result = std::max(result, -prices[i] + self(self, i + 1, 1));
            }
            return memo[i][holding] = result;
        };
        
        return dfs(dfs, 0, 0);
    }
};
