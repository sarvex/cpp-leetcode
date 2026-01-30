/**
 * @brief Minimax DP for stone game optimal play
 * @intuition First player can always win with optimal strategy (mathematical proof)
 * @approach Use memoization: f[i][j] = max score difference achievable from piles[i..j].
 *           At each turn, choose left or right pile to maximize own advantage.
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto stoneGame(const std::vector<int>& piles) -> bool {
        const int n = static_cast<int>(piles.size());
        std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));
        
        auto dfs = [&](auto&& self, int i, int j) -> int {
            if (i > j) return 0;
            if (f[i][j] != 0) return f[i][j];
            return f[i][j] = std::max(piles[i] - self(self, i + 1, j),
                                       piles[j] - self(self, i, j - 1));
        };
        
        return dfs(dfs, 0, n - 1) > 0;
    }
};
