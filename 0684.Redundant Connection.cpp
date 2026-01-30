/**
 * @brief Find edge that creates cycle in undirected graph
 * @intuition Union-Find: edge connecting already-connected nodes creates cycle
 * @approach Process edges, return first edge where both nodes share same root
 * @complexity Time: O(n * alpha(n)), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        
        auto find = [&](this auto&& find, int x) -> int {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        
        for (const auto& e : edges) {
            const int pa = find(e[0] - 1);
            const int pb = find(e[1] - 1);
            if (pa == pb) {
                return e;
            }
            p[pa] = pb;
        }
        return {};
    }
};
