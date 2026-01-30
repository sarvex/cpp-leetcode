/**
 * @brief Check all 3x3 subgrids for magic square property
 * @intuition Magic square: distinct 1-9, all rows/cols/diagonals sum to 15
 * @approach For each 3x3 subgrid, verify: all values are distinct 1-9,
 *           rows sum to 15, columns sum to 15, both diagonals sum to 15.
 * @complexity Time: O(m * n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto numMagicSquaresInside(
        const std::vector<std::vector<int>>& grid) -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        auto check = [&](int i, int j) -> int {
            if (i + 3 > m || j + 3 > n) return 0;
            
            std::vector<int> cnt(16);
            std::vector<int> row(3);
            std::vector<int> col(3);
            int a = 0, b = 0;
            
            for (int x = i; x < i + 3; ++x) {
                for (int y = j; y < j + 3; ++y) {
                    const int v = grid[x][y];
                    if (v < 1 || v > 9 || ++cnt[v] > 1) {
                        return 0;
                    }
                    row[x - i] += v;
                    col[y - j] += v;
                    if (x - i == y - j) {
                        a += v;
                    }
                    if (x - i + y - j == 2) {
                        b += v;
                    }
                }
            }
            
            if (a != b) return 0;
            for (int k = 0; k < 3; ++k) {
                if (row[k] != a || col[k] != a) {
                    return 0;
                }
            }
            return 1;
        };
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};
