/**
 * @brief Traverse matrix diagonally with alternating directions
 * @intuition Collect elements along each diagonal, reverse odd diagonals
 * @approach For diagonal k, start at (0,k) or (k-n+1, n-1), alternate direction
 * @complexity Time: O(m * n), Space: O(min(m, n))
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findDiagonalOrder(const std::vector<std::vector<int>>& mat) const
        -> std::vector<int> {
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat[0].size());
        std::vector<int> ans;
        ans.reserve(m * n);

        std::vector<int> diagonal;

        for (int k = 0; k < m + n - 1; ++k) {
            const int startRow = k < n ? 0 : k - n + 1;
            const int startCol = k < n ? k : n - 1;

            int i = startRow;
            int j = startCol;
            while (i < m && j >= 0) {
                diagonal.push_back(mat[i++][j--]);
            }

            if (k % 2 == 0) {
                std::reverse(diagonal.begin(), diagonal.end());
            }

            for (const int v : diagonal) {
                ans.push_back(v);
            }
            diagonal.clear();
        }

        return ans;
    }
};
