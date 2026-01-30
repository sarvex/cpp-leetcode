/**
 * @brief Count distinct islands considering rotations and reflections
 * @intuition Normalize island shapes by computing all 8 transformations
 * @approach DFS to find islands, normalize with all symmetries, use set for uniqueness
 * @complexity Time: O(m*n*k*log(k)) where k is island size, Space: O(m*n)
 */
class Solution final {
    using Point = std::pair<int, int>;
    
public:
    [[nodiscard]] int numDistinctIslands2(std::vector<std::vector<int>>& grid) {
        std::set<std::vector<Point>> uniqueIslands;
        const int rows = static_cast<int>(grid.size());
        const int cols = static_cast<int>(grid[0].size());
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    std::vector<Point> shape;
                    dfs(i, j, grid, shape);
                    uniqueIslands.insert(normalize(shape));
                }
            }
        }
        return static_cast<int>(uniqueIslands.size());
    }

private:
    [[nodiscard]] static std::vector<Point> normalize(std::vector<Point>& shape) {
        std::vector<std::vector<Point>> shapes(8);
        for (const auto& [i, j] : shape) {
            shapes[0].emplace_back(i, j);
            shapes[1].emplace_back(i, -j);
            shapes[2].emplace_back(-i, j);
            shapes[3].emplace_back(-i, -j);
            shapes[4].emplace_back(j, i);
            shapes[5].emplace_back(j, -i);
            shapes[6].emplace_back(-j, -i);
            shapes[7].emplace_back(-j, i);
        }
        for (auto& s : shapes) {
            std::ranges::sort(s);
            for (int k = static_cast<int>(s.size()) - 1; k >= 0; --k) {
                s[k].first -= s[0].first;
                s[k].second -= s[0].second;
            }
        }
        std::ranges::sort(shapes);
        return shapes[0];
    }

    static void dfs(const int i, const int j, std::vector<std::vector<int>>& grid, 
                    std::vector<Point>& shape) {
        shape.emplace_back(i, j);
        grid[i][j] = 0;
        constexpr std::array<int, 5> dirs{-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            const int x = i + dirs[k];
            const int y = j + dirs[k + 1];
            if (x >= 0 && x < static_cast<int>(grid.size()) && 
                y >= 0 && y < static_cast<int>(grid[0].size()) && grid[x][y] == 1) {
                dfs(x, y, grid, shape);
            }
        }
    }
};
