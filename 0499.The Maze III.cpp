/**
 * @brief Find shortest path with lexicographically smallest instructions to hole
 * @intuition BFS with distance tracking, prefer lexicographically smaller paths
 * @approach Roll ball in all directions, update if shorter or same distance but smaller path
 * @complexity Time: O(m * n * max(m, n)), Space: O(m * n)
 */
#include <climits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findShortestWay(std::vector<std::vector<int>>& maze,
                                        std::vector<int>& ball,
                                        std::vector<int>& hole) const -> std::string {
        const int m = static_cast<int>(maze.size());
        const int n = static_cast<int>(maze[0].size());
        const int startRow = ball[0];
        const int startCol = ball[1];
        const int holeRow = hole[0];
        const int holeCol = hole[1];

        std::queue<std::pair<int, int>> q;
        q.push({startRow, startCol});

        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        dist[startRow][startCol] = 0;

        std::vector<std::vector<std::string>> path(m, std::vector<std::string>(n, ""));

        const std::vector<std::tuple<int, int, char>> dirs = {
            {-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}
        };

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (const auto& [dr, dc, dir] : dirs) {
                int x = row;
                int y = col;
                int steps = dist[row][col];

                while (x + dr >= 0 && x + dr < m && y + dc >= 0 && y + dc < n &&
                       maze[x + dr][y + dc] == 0 && (x != holeRow || y != holeCol)) {
                    x += dr;
                    y += dc;
                    ++steps;
                }

                const std::string newPath = path[row][col] + dir;
                if (dist[x][y] > steps || (dist[x][y] == steps && newPath < path[x][y])) {
                    dist[x][y] = steps;
                    path[x][y] = newPath;
                    if (x != holeRow || y != holeCol) {
                        q.push({x, y});
                    }
                }
            }
        }

        return path[holeRow][holeCol].empty() ? "impossible" : path[holeRow][holeCol];
    }
};
