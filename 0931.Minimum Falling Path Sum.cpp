/**
 * @brief DP for minimum falling path sum in matrix
 * @intuition Each cell depends on three cells from row above
 * @approach Use 1D DP array; for each row update from adjacent cells above
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minFallingPathSum(const vector<vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());
        vector<int> f(n);
        for (const auto& row : matrix) {
            auto g = f;
            for (int j = 0; j < n; ++j) {
                if (j > 0) {
                    g[j] = min(g[j], f[j - 1]);
                }
                if (j + 1 < n) {
                    g[j] = min(g[j], f[j + 1]);
                }
                g[j] += row[j];
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
