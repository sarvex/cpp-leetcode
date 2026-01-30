/**
 * @brief Find edge causing invalid directed tree (node with two parents or cycle)
 * @intuition Handle two cases: node with two parents, or cycle without two-parent node
 * @approach Track in-degrees, use Union-Find to detect cycles
 * @complexity Time: O(n * alpha(n)), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> ind(n);
        
        for (const auto& e : edges) {
            ++ind[e[1] - 1];
        }
        
        vector<int> dup;
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.push_back(i);
            }
        }
        
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        
        auto find = [&](this auto&& find, int x) -> int {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        
        if (!dup.empty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup[1]) {
                    continue;
                }
                const int pu = find(edges[i][0] - 1);
                const int pv = find(edges[i][1] - 1);
                if (pu == pv) {
                    return edges[dup[0]];
                }
                p[pu] = pv;
            }
            return edges[dup[1]];
        }
        
        for (int i = 0;; ++i) {
            const int pu = find(edges[i][0] - 1);
            const int pv = find(edges[i][1] - 1);
            if (pu == pv) {
                return edges[i];
            }
            p[pu] = pv;
        }
    }
};
