/**
 * @brief Kruskal's algorithm to find minimum spanning tree cost
 * @intuition Sort edges by cost and greedily add edges that connect different components
 * @approach Sort connections by cost. Use union-find to track connected components.
 *           Add edge if it connects two different components. Return -1 if not all connected.
 * @complexity Time: O(E log E + E * alpha(n)), Space: O(n) where E is number of edges
 */
class Solution final {
public:
    [[nodiscard]] static int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        ranges::sort(connections, [](const auto& a, const auto& b) { return a[2] < b[2]; });
        int ans = 0;
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (const auto& e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }
};
