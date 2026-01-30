/**
 * @brief Probability knight stays on board after k moves
 * @intuition DP: f[h][i][j] = probability of being at (i,j) after h moves
 * @approach Iterate moves, for each cell sum probabilities from 8 knight moves
 * @complexity Time: O(k * n^2), Space: O(k * n^2)
 */
class Solution final {
public:
    [[nodiscard]] static double knightProbability(const int n, const int k, const int row, const int column) {
        vector<vector<vector<double>>> f(k + 1, vector<vector<double>>(n, vector<double>(n)));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        
        constexpr int dirs[] = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int p = 0; p < 8; ++p) {
                        const int x = i + dirs[p];
                        const int y = j + dirs[p + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            f[h][i][j] += f[h - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return f[k][row][column];
    }
};
