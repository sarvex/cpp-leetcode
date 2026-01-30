/**
 * @brief Union-Find to count groups of similar strings
 * @intuition Two strings are similar if they differ by exactly 0 or 2 positions (swap)
 * @approach Use Union-Find. For each pair of strings, check if similar (<=2 diffs).
 *           If similar, union them. Count remaining disjoint groups.
 * @complexity Time: O(n^2 * m * α(n)), Space: O(n)
 */
class Solution final {
    class UnionFind {
        std::vector<int> p, sz;
    public:
        explicit UnionFind(int n) : p(n), sz(n, 1) {
            std::iota(p.begin(), p.end(), 0);
        }
        
        [[nodiscard]] auto find(int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        }
        
        auto unite(int a, int b) -> bool {
            const int pa = find(a), pb = find(b);
            if (pa == pb) return false;
            if (sz[pa] > sz[pb]) {
                p[pb] = pa;
                sz[pa] += sz[pb];
            } else {
                p[pa] = pb;
                sz[pb] += sz[pa];
            }
            return true;
        }
    };

public:
    [[nodiscard]] static auto numSimilarGroups(const std::vector<std::string>& strs) -> int {
        const int n = static_cast<int>(strs.size());
        const int m = static_cast<int>(strs[0].size());
        int cnt = n;
        UnionFind uf(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    diff += strs[i][k] != strs[j][k];
                }
                if (diff <= 2 && uf.unite(i, j)) {
                    --cnt;
                }
            }
        }
        return cnt;
    }
};
