/**
 * @brief Minimum swaps to transform board to chessboard pattern
 * @intuition Valid chessboard has exactly 2 row/col patterns; count swap distance
 * @approach Verify validity with masks, compute minimum swaps for rows and cols
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int movesToChessboard(const std::vector<std::vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        const int mask = (1 << n) - 1;
        int rowMask = 0, colMask = 0;
        
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }
        
        const int revRowMask = mask ^ rowMask;
        const int revColMask = mask ^ colMask;
        int sameRowCount = 0, sameColCount = 0;
        
        for (int i = 0; i < n; ++i) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= board[i][j] << j;
                curColMask |= board[j][i] << j;
            }
            if (curRowMask != rowMask && curRowMask != revRowMask) return -1;
            if (curColMask != colMask && curColMask != revColMask) return -1;
            sameRowCount += (curRowMask == rowMask);
            sameColCount += (curColMask == colMask);
        }
        
        const int rowSwaps = computeSwaps(rowMask, sameRowCount, n);
        const int colSwaps = computeSwaps(colMask, sameColCount, n);
        return (rowSwaps == -1 || colSwaps == -1) ? -1 : rowSwaps + colSwaps;
    }

private:
    [[nodiscard]] static int computeSwaps(const int mask, const int sameCount, const int n) {
        const int ones = __builtin_popcount(mask);
        if (n & 1) {
            if (std::abs(n - ones * 2) != 1 || std::abs(n - sameCount * 2) != 1) return -1;
            if (ones == n / 2) {
                return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            }
            return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
        } else {
            if (ones != n / 2 || sameCount != n / 2) return -1;
            const int swaps0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            const int swaps1 = n / 2 - __builtin_popcount(mask & 0x55555555);
            return std::min(swaps0, swaps1);
        }
    }
};
