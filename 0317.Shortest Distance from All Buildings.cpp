/**
 * @brief BFS from each building to find optimal empty land
 * @intuition Multi-source BFS from all buildings, track reachability count
 * @approach BFS from each building, accumulate distances, check all buildings reachable
 * @complexity Time: O(m^2 * n^2), Space: O(mn)
 */
#include <array>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int shortestDistance(std::vector<std::vector<int>>& grid) const {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        using pii = std::pair<int, int>;
        std::queue<pii> q;
        int totalBuildings = 0;
        std::vector<std::vector<int>> cnt(m, std::vector<int>(n));
        std::vector<std::vector<int>> dist(m, std::vector<int>(n));
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++totalBuildings;
                    q.emplace(i, j);
                    std::vector<std::vector<bool>> vis(m, std::vector<bool>(n));
                    int d = 0;
                    
                    while (!q.empty()) {
                        ++d;
                        for (int k = static_cast<int>(q.size()); k > 0; --k) {
                            auto [ci, cj] = q.front();
                            q.pop();
                            
                            for (int dir = 0; dir < 4; ++dir) {
                                const int x = ci + dirs[dir];
                                const int y = cj + dirs[dir + 1];
                                if (x >= 0 && x < m && y >= 0 && y < n && 
                                    grid[x][y] == 0 && !vis[x][y]) {
                                    ++cnt[x][y];
                                    dist[x][y] += d;
                                    q.emplace(x, y);
                                    vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == totalBuildings) {
                    ans = std::min(ans, dist[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
