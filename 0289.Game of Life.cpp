/**
 * @brief In-place Game of Life using state encoding
 * @intuition Encode current and next state in same cell (2 = was 1, -1 = will be 1)
 * @approach Count live neighbors, encode transitions, decode final state
 * @complexity Time: O(m*n), Space: O(1)
 */
class Solution final {
public:
    static void gameOfLife(vector<vector<int>>& board) {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
