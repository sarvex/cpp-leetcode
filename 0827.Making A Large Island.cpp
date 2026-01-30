/**
 * @brief DFS to label islands, then try flipping each 0 to maximize area
 * @intuition Label each island with unique ID and size; check neighbors when flipping 0
 * @approach First pass: DFS to assign island IDs and compute sizes. Second pass:
 *           for each 0 cell, sum sizes of unique neighboring islands + 1.
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto largestIsland(std::vector<std::vector<int>>& grid) -> int {
        const int n = static_cast<int>(grid.size());
        std::vector<std::vector<int>> p(n, std::vector<int>(n, 0));
        std::vector<int> cnt(n * n + 1, 0);
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        int root = 0;
        int ans = 0;
        
        auto dfs = [&](auto&& self, int i, int j) -> int {
            p[i][j] = root;
            ++cnt[root];
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && !p[x][y]) {
                    self(self, x, y);
                }
            }
            return cnt[root];
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !p[i][j]) {
                    ++root;
                    ans = std::max(ans, dfs(dfs, i, j));
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    std::unordered_set<int> s;
                    for (int k = 0; k < 4; ++k) {
                        const int x = i + dirs[k];
                        const int y = j + dirs[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            s.insert(p[x][y]);
                        }
                    }
                    int t = 1;
                    for (const int id : s) {
                        t += cnt[id];
                    }
                    ans = std::max(ans, t);
                }
            }
        }
        return ans;
    }
};
