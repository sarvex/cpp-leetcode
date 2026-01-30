/**
 * @brief DP with memoization for stock trading with cooldown
 * @intuition Track states: holding stock or not, with cooldown after selling
 * @approach DFS with memoization, state is (day, holding), skip one day after sell
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxProfit(const vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        vector<vector<int>> memo(n, vector<int>(2, -1));
        
        function<int(int, int)> dfs = [&](int i, int holding) -> int {
            if (i >= n) {
                return 0;
            }
            if (memo[i][holding] != -1) {
                return memo[i][holding];
            }
            int ans = dfs(i + 1, holding);
            if (holding != 0) {
                ans = max(ans, prices[i] + dfs(i + 2, 0));
            } else {
                ans = max(ans, -prices[i] + dfs(i + 1, 1));
            }
            return memo[i][holding] = ans;
        };
        
        return dfs(0, 0);
    }
};
