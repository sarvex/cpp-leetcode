/**
 * @brief BFS with bitmask state for collecting all keys
 * @intuition State = (position, collected keys); BFS finds shortest path
 * @approach Use BFS where state includes position and key bitmask. Can pass through
 *           lock only if have corresponding key. Track visited (pos, keymask) states.
 * @complexity Time: O(m * n * 2^k), Space: O(m * n * 2^k)
 */
class Solution final {
public:
    [[nodiscard]] static auto shortestPathAllKeys(
        const std::vector<std::string>& grid) -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        int k = 0, si = 0, sj = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const char c = grid[i][j];
                if (std::islower(c)) ++k;
                else if (c == '@') {
                    si = i;
                    sj = j;
                }
            }
        }
        
        std::queue<std::tuple<int, int, int>> q;
        q.emplace(si, sj, 0);
        std::vector<std::vector<std::vector<bool>>> vis(
            m, std::vector<std::vector<bool>>(n, std::vector<bool>(1 << k)));
        vis[si][sj][0] = true;
        
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        int ans = 0;
        
        while (!q.empty()) {
            for (int t = static_cast<int>(q.size()); t > 0; --t) {
                auto [i, j, state] = q.front();
                q.pop();
                
                if (state == (1 << k) - 1) return ans;
                
                for (int h = 0; h < 4; ++h) {
                    const int x = i + dirs[h], y = j + dirs[h + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        const char c = grid[x][y];
                        if (c == '#') continue;
                        if (std::isupper(c) && ((state >> (c - 'A')) & 1) == 0) continue;
                        
                        int nxt = state;
                        if (std::islower(c)) {
                            nxt |= 1 << (c - 'a');
                        }
                        
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.emplace(x, y, nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
