/**
 * @brief Flood fill using DFS
 * @intuition Starting from source, recursively fill connected cells of same color
 * @approach DFS with 4-directional neighbors, skip if already target color
 * @complexity Time: O(m*n), Space: O(m*n) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::vector<int>> floodFill(
            std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        const int m = static_cast<int>(image.size());
        const int n = static_cast<int>(image[0].size());
        const int originalColor = image[sr][sc];
        
        if (originalColor == color) {
            return image;
        }
        
        constexpr std::array<int, 5> dirs{-1, 0, 1, 0, -1};
        auto dfs = [&](auto&& self, const int i, const int j) -> void {
            image[i][j] = color;
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == originalColor) {
                    self(self, x, y);
                }
            }
        };
        
        dfs(dfs, sr, sc);
        return image;
    }
};
