/**
 * @brief Union-Find with reverse time processing for falling bricks
 * @intuition Process hits in reverse order, adding bricks back and tracking connections to top
 * @approach Use Union-Find with virtual node for top row. Remove all hit bricks first,
 *           then add them back in reverse order. The difference in connected component
 *           size to top gives the number of falling bricks.
 * @complexity Time: O(hits * α(m*n)), Space: O(m * n)
 */
class Solution final {
    std::vector<int> p;
    std::vector<int> sz;

    auto find(int x) -> int {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    auto merge(int a, int b) -> void {
        const int pa = find(a);
        const int pb = find(b);
        if (pa != pb) {
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
    }

public:
    [[nodiscard]] auto hitBricks(std::vector<std::vector<int>>& grid,
                                  const std::vector<std::vector<int>>& hits) -> std::vector<int> {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        p.resize(m * n + 1);
        sz.resize(m * n + 1);
        for (int i = 0; i < static_cast<int>(p.size()); ++i) {
            p[i] = i;
            sz[i] = 1;
        }
        
        std::vector<std::vector<int>> g(m, std::vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = grid[i][j];
            }
        }
        
        for (const auto& h : hits) {
            g[h[0]][h[1]] = 0;
        }
        
        for (int j = 0; j < n; ++j) {
            if (g[0][j] == 1) {
                merge(j, m * n);
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) continue;
                if (g[i - 1][j] == 1) {
                    merge(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && g[i][j - 1] == 1) {
                    merge(i * n + j, i * n + j - 1);
                }
            }
        }
        
        std::vector<int> ans(hits.size());
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        
        for (int k = static_cast<int>(hits.size()) - 1; k >= 0; --k) {
            const int i = hits[k][0];
            const int j = hits[k][1];
            if (grid[i][j] == 0) continue;
            
            g[i][j] = 1;
            const int prev = sz[find(m * n)];
            
            if (i == 0) {
                merge(j, m * n);
            }
            
            for (int l = 0; l < 4; ++l) {
                const int x = i + dirs[l];
                const int y = j + dirs[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1) {
                    merge(i * n + j, x * n + y);
                }
            }
            
            const int curr = sz[find(m * n)];
            ans[k] = std::max(0, curr - prev - 1);
        }
        return ans;
    }
};
