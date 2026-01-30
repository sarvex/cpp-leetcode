/**
 * @brief Find largest square with all 1s on its border
 * @intuition Precompute continuous 1s going down and right from each cell
 * @approach Build arrays for consecutive 1s extending down and right. For each possible
 *           square size, check if all four borders have enough consecutive 1s.
 * @complexity Time: O(m * n * min(m,n)), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static int largest1BorderedSquare(const vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> down(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = i + 1 < m ? down[i + 1][j] + 1 : 1;
                    right[i][j] = j + 1 < n ? right[i][j + 1] + 1 : 1;
                }
            }
        }
        for (int k = min(m, n); k > 0; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k && right[i + k - 1][j] >= k
                        && down[i][j + k - 1] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
};
