/**
 * @brief Minimum time to swim from top-left to bottom-right
 * @intuition Process cells in order of elevation, use Union-Find for connectivity
 * @approach Sort cells by elevation, union adjacent visited cells
 * @complexity Time: O(n^2 log n), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] int swimInWater(std::vector<std::vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        parent_.resize(n * n);
        std::iota(parent_.begin(), parent_.end(), 0);
        
        std::vector<int> elevationToCell(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                elevationToCell[grid[i][j]] = i * n + j;
            }
        }
        
        constexpr std::array<int, 5> dirs{-1, 0, 1, 0, -1};
        for (int t = 0; t < n * n; ++t) {
            const int cell = elevationToCell[t];
            const int i = cell / n;
            const int j = cell % n;
            
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                    parent_[find(x * n + y)] = find(cell);
                }
            }
            if (find(0) == find(n * n - 1)) {
                return t;
            }
        }
        return -1;
    }

private:
    std::vector<int> parent_;

    [[nodiscard]] int find(const int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }
};
