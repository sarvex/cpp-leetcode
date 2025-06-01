#include <bitset>
#include <cstddef>

class Solution final {
public:
    /**
/**
 * Bitmask DFS for N-Queens Counting
 *
 * @intuition
 * Use bitsets to track column and diagonal attacks, recursing row by row.
 *
 * @approach
 * Place queens row-wise, marking columns and diagonals as occupied. Use DFS with backtracking, leveraging bitsets for O(1) attack checks. Count solutions when all rows are filled.
 *
 * @complexity
 * Time: O(N!) in the worst case
 * Space: O(N) for recursion and bitsets
 */
    int totalNQueens(const int n) const {
        constexpr size_t MAX_N = 20; // Leetcode constraint
        std::bitset<MAX_N> cols, diag1, diag2;
        int count = 0;
        auto dfs = [&](auto&& self, int row) -> void {
            if (row == n) {
                ++count;
                return;
            }
            for (int col = 0; col < n; ++col) {
                const int d1 = row - col + n;
                const int d2 = row + col;
                if (cols[col] || diag1[d1] || diag2[d2]) continue;
                cols[col] = diag1[d1] = diag2[d2] = true;
                self(self, row + 1);
                cols[col] = diag1[d1] = diag2[d2] = false;
            }
        };
        dfs(dfs, 0);
        return count;
    }
};
