/**
 * @brief Candy Crush board simulation
 * @intuition Mark matches with negative values, then drop and repeat
 * @approach Iterate: mark horizontal/vertical matches, gravity drop, repeat until stable
 * @complexity Time: O((m*n)^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::vector<int>> candyCrush(
            std::vector<std::vector<int>>& board) {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        bool hasMatches = true;
        
        while (hasMatches) {
            hasMatches = false;
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n - 2; ++j) {
                    const int val = std::abs(board[i][j]);
                    if (val != 0 && val == std::abs(board[i][j + 1]) && 
                        val == std::abs(board[i][j + 2])) {
                        hasMatches = true;
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = -val;
                    }
                }
            }
            
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m - 2; ++i) {
                    const int val = std::abs(board[i][j]);
                    if (val != 0 && val == std::abs(board[i + 1][j]) && 
                        val == std::abs(board[i + 2][j])) {
                        hasMatches = true;
                        board[i][j] = board[i + 1][j] = board[i + 2][j] = -val;
                    }
                }
            }
            
            if (hasMatches) {
                for (int j = 0; j < n; ++j) {
                    int writePos = m - 1;
                    for (int i = m - 1; i >= 0; --i) {
                        if (board[i][j] > 0) {
                            board[writePos--][j] = board[i][j];
                        }
                    }
                    while (writePos >= 0) {
                        board[writePos--][j] = 0;
                    }
                }
            }
        }
        return board;
    }
};
