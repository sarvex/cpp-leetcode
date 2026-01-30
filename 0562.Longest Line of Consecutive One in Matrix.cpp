/**
 * @brief Track longest line in 4 directions using DP
 * @intuition Track consecutive ones ending at each cell for horizontal, vertical, diagonal, anti-diagonal
 * @approach Use 4 DP arrays; for each 1, update from appropriate predecessor
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static int longestLine(const vector<vector<int>>& mat) {
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat[0].size());
        
        vector<vector<int>> horizontal(m + 2, vector<int>(n + 2));
        vector<vector<int>> vertical(m + 2, vector<int>(n + 2));
        vector<vector<int>> diagonal(m + 2, vector<int>(n + 2));
        vector<vector<int>> antiDiag(m + 2, vector<int>(n + 2));
        
        int ans = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i - 1][j - 1]) {
                    horizontal[i][j] = horizontal[i - 1][j] + 1;
                    vertical[i][j] = vertical[i][j - 1] + 1;
                    diagonal[i][j] = diagonal[i - 1][j - 1] + 1;
                    antiDiag[i][j] = antiDiag[i - 1][j + 1] + 1;
                    ans = max({ans, horizontal[i][j], vertical[i][j], 
                              diagonal[i][j], antiDiag[i][j]});
                }
            }
        }
        
        return ans;
    }
};
