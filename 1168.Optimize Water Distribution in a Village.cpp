/**
 * @brief Minimum spanning tree with virtual node for wells
 * @intuition Treat building a well as connecting to a virtual source node with edge cost = well cost
 * @approach Add virtual node 0 with edges to each house (well costs). Combine with pipe edges.
 *           Run Kruskal's MST on combined graph.
 * @complexity Time: O((n + m) log(n + m)), Space: O(n + m) where m is pipe count
 */
class Solution final {
public:
    [[nodiscard]] static int minCostToSupplyWater(int n, const vector<int>& wells,
                                                   vector<vector<int>>& pipes) {
        for (int i = 0; i < n; ++i) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        ranges::sort(pipes, [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        vector<int> p(n + 1);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        int ans = 0;
        for (const auto& x : pipes) {
            int pa = find(x[0]), pb = find(x[1]);
            if (pa == pb) {
                continue;
            }
            p[pa] = pb;
            ans += x[2];
            if (--n == 0) {
                break;
            }
        }
        return ans;
    }
};
