/**
 * @brief DFS backtracking to find word path in grid
 * @intuition Explore all 4 directions from each cell, marking visited cells
 * @approach Start DFS from each cell; mark cell as visited during exploration,
 *           restore on backtrack; return true if complete word is found
 * @complexity Time: O(m * n * 4^L), Space: O(L) where L is word length
 */
class Solution final {
public:
    [[nodiscard]] static auto exist(vector<vector<char>>& board, const string& word) -> bool {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        
        auto dfs = [&](this auto&& dfs, const int i, const int j, const int k) -> bool {
            if (k == static_cast<int>(word.size()) - 1) {
                return board[i][j] == word[k];
            }
            if (board[i][j] != word[k]) {
                return false;
            }
            
            const char original = board[i][j];
            board[i][j] = '\0';
            
            for (int d = 0; d < 4; ++d) {
                const int x = i + dirs[d];
                const int y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '\0' && dfs(x, y, k + 1)) {
                    return true;
                }
            }
            
            board[i][j] = original;
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
