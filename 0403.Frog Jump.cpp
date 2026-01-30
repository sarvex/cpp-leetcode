/**
 * @brief Determine if frog can cross river by jumping on stones
 * @intuition From each stone, frog can jump k-1, k, or k+1 units if last jump was k
 * @approach DFS with memoization, track position and last jump size
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto canCross(std::vector<int>& stones) -> bool {
        const auto n = static_cast<int>(stones.size());
        std::vector<std::vector<int>> f(n, std::vector<int>(n, -1));

        std::unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[stones[i]] = i;
        }

        std::function<bool(int, int)> dfs = [&](int i, int k) -> bool {
            if (i == n - 1) {
                return true;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            for (int j = k - 1; j <= k + 1; ++j) {
                if (j > 0 && pos.contains(stones[i] + j) && dfs(pos[stones[i] + j], j)) {
                    return f[i][k] = true;
                }
            }
            return f[i][k] = false;
        };

        return dfs(0, 0);
    }
};
