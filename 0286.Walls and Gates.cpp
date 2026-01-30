/**
 * @brief Multi-source BFS from gates to fill distances
 * @intuition Start BFS from all gates simultaneously
 * @approach Add all gates to queue, expand layer by layer
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    static void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = static_cast<int>(rooms.size());
        const int n = static_cast<int>(rooms[0].size());
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        
        constexpr array<int, 5> dirs = {-1, 0, 1, 0, -1};
        int d = 0;
        
        while (!q.empty()) {
            ++d;
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                auto [r, c] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    const int x = r + dirs[j];
                    const int y = c + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == INT_MAX) {
                        rooms[x][y] = d;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
