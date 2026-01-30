/**
 * @brief Simulate Minesweeper reveal action using DFS
 * @intuition Click on mine ends game; empty cell reveals recursively based on adjacent mines
 * @approach If click hits mine, mark 'X'. Otherwise DFS: count adjacent mines,
 *           if any display count, else mark 'B' and recurse to all empty neighbors.
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto updateBoard(vector<vector<char>>& board, 
                                           const vector<int>& click) -> vector<vector<char>>& {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        const int i = click[0], j = click[1];

        auto dfs = [&](this auto&& dfs, int row, int col) -> void {
            int cnt = 0;
            for (int x = row - 1; x <= row + 1; ++x) {
                for (int y = col - 1; y <= col + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                        ++cnt;
                    }
                }
            }
            
            if (cnt > 0) {
                board[row][col] = static_cast<char>('0' + cnt);
            } else {
                board[row][col] = 'B';
                for (int x = row - 1; x <= row + 1; ++x) {
                    for (int y = col - 1; y <= col + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                            dfs(x, y);
                        }
                    }
                }
            }
        };

        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            dfs(i, j);
        }
        return board;
    }
};
