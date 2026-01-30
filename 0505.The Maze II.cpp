/**
 * @brief BFS to find shortest distance in rolling ball maze
 * @intuition Ball rolls until hitting wall; need to track minimum distance to each stop position
 * @approach BFS with distance tracking. From each position, roll in all 4 directions until wall,
 *           counting steps. Update distance if shorter path found and add to queue.
 * @complexity Time: O(m * n * max(m, n)), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto shortestDistance(vector<vector<int>>& maze, 
                                                const vector<int>& start, 
                                                const vector<int>& destination) -> int {
        const int m = static_cast<int>(maze.size());
        const int n = static_cast<int>(maze[0].size());
        constexpr int INF = 0x3f3f3f3f;
        
        vector<vector<int>> dist(m, vector<int>(n, INF));
        const int si = start[0], sj = start[1];
        const int di = destination[0], dj = destination[1];
        dist[si][sj] = 0;
        
        queue<pair<int, int>> q;
        q.emplace(si, sj);
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, k = dist[i][j];
                const int a = dirs[d], b = dirs[d + 1];
                
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                    ++k;
                }
                
                if (k < dist[x][y]) {
                    dist[x][y] = k;
                    q.emplace(x, y);
                }
            }
        }
        return dist[di][dj] == INF ? -1 : dist[di][dj];
    }
};
