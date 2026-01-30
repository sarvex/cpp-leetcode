/**
 * @brief Minimum cost climbing stairs using memoized DP
 * @intuition Each step can be reached from previous or two steps back
 * @approach Memoized recursion: min cost to reach top from index i
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minCostClimbingStairs(const std::vector<int>& cost) {
        const int n = static_cast<int>(cost.size());
        std::vector<int> memo(n, -1);
        
        auto dfs = [&](auto&& self, const int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (memo[i] < 0) {
                memo[i] = cost[i] + std::min(self(self, i + 1), self(self, i + 2));
            }
            return memo[i];
        };
        
        return std::min(dfs(dfs, 0), dfs(dfs, 1));
    }
};
