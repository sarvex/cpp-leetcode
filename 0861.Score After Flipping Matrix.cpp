/**
 * @brief Greedy row and column flipping for maximum binary score
 * @intuition MSB should be 1 for all rows; then maximize 1s in each column
 * @approach First, flip rows to make leftmost column all 1s. Then for each
 *           column, count 1s and take max(count, m-count) for the contribution.
 * @complexity Time: O(m * n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto matrixScore(std::vector<std::vector<int>>& grid) -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            ans += std::max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
};
