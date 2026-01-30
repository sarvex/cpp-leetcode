/**
 * @brief Determine if ball can stop at destination in maze
 * @intuition Ball rolls until hitting wall, DFS from each stop position
 * @approach From each position, try all 4 directions until wall, mark visited
 * @complexity Time: O(m * n), Space: O(m * n)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto hasPath(std::vector<std::vector<int>>& maze,
                                std::vector<int>& start,
                                std::vector<int>& destination) const -> bool {
        const int m = static_cast<int>(maze.size());
        const int n = static_cast<int>(maze[0].size());
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        auto dfs = [&](this auto&& dfs, int row, int col) -> bool {
            if (visited[row][col]) {
                return false;
            }
            visited[row][col] = true;

            if (row == destination[0] && col == destination[1]) {
                return true;
            }

            constexpr int dirs[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int x = row;
                int y = col;
                const int dx = dirs[k];
                const int dy = dirs[k + 1];

                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n &&
                       maze[x + dx][y + dy] == 0) {
                    x += dx;
                    y += dy;
                }

                if (dfs(x, y)) {
                    return true;
                }
            }

            return false;
        };

        return dfs(start[0], start[1]);
    }
};
