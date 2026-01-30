/**
 * @brief Validate if Tic-Tac-Toe board state is reachable
 * @intuition X goes first; counts must be equal or X has one more
 * @approach Count pieces, check win conditions consistency with counts
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool validTicTacToe(const std::vector<std::string>& board) {
        auto countPiece = [&](const char piece) -> int {
            int count = 0;
            for (const auto& row : board) {
                for (const char c : row) {
                    count += (c == piece);
                }
            }
            return count;
        };
        
        auto hasWon = [&](const char piece) -> bool {
            for (int i = 0; i < 3; ++i) {
                if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece) return true;
                if (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece) return true;
            }
            if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) return true;
            return board[0][2] == piece && board[1][1] == piece && board[2][0] == piece;
        };
        
        const int xCount = countPiece('X');
        const int oCount = countPiece('O');
        
        if (xCount != oCount && xCount - 1 != oCount) return false;
        if (hasWon('X') && xCount - 1 != oCount) return false;
        if (hasWon('O') && xCount != oCount) return false;
        return true;
    }
};
