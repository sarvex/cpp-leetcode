/**
 * @brief Calculate volume of water trapped in 2D elevation map
 * @intuition Water level at each cell determined by minimum height boundary
 * @approach BFS from border using min-heap, process cells in height order
 * @complexity Time: O(mn log(mn)) Space: O(mn)
 */
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto trapRainWater(std::vector<std::vector<int>>& heightMap) const -> int {
        using tii = std::tuple<int, int, int>;
        std::priority_queue<tii, std::vector<tii>, std::greater<tii>> pq;

        const int m = static_cast<int>(heightMap.size());
        const int n = static_cast<int>(heightMap[0].size());

        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];

                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += std::max(0, h - heightMap[x][y]);
                    vis[x][y] = true;
                    pq.emplace(std::max(heightMap[x][y], h), x, y);
                }
            }
        }

        return ans;
    }
};
