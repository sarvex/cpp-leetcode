/**
 * @brief BFS from each building to find optimal empty land
 * @intuition Multi-source BFS from all buildings, track reachability count
 * @approach BFS from each building, accumulate distances, check all buildings reachable
 * @complexity Time: O(m^2 * n^2), Space: O(mn)
 */
class Solution final {
public:
    [[nodiscard]] static int shortestDistance(vector<vector<int>>& grid) {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        queue<pair<int, int>> q;
        int totalBuildings = 0;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<vector<int>> dist(m, vector<int>(n));
        constexpr array<int, 5> dirs = {-1, 0, 1, 0, -1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++totalBuildings;
                    q.emplace(i, j);
                    vector<vector<bool>> vis(m, vector<bool>(n));
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
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
