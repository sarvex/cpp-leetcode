/**
 * @brief O(1) Tic-Tac-Toe move validation
 * @intuition Track count per row, column, and diagonals per player
 * @approach Increment counters on move, check if any reaches n
 * @complexity Time: O(1) per move, Space: O(n)
 */
#include <vector>

class TicTacToe final {
public:
    explicit TicTacToe(int n) : n_(n), counts_(2, std::vector<int>((n << 1) + 2, 0)) {}

    [[nodiscard]] int move(int row, int col, int player) {
        std::vector<int>& cur = counts_[player - 1];
        ++cur[row];
        ++cur[n_ + col];
        if (row == col) {
            ++cur[n_ << 1];
        }
        if (row + col == n_ - 1) {
            ++cur[(n_ << 1) | 1];
        }
        if (cur[row] == n_ || cur[n_ + col] == n_ || 
            cur[n_ << 1] == n_ || cur[(n_ << 1) | 1] == n_) {
            return player;
        }
        return 0;
    }

private:
    int n_;
    std::vector<std::vector<int>> counts_;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
