/**
 * @brief Greedy graph coloring with 4 colors
 * @intuition With max degree 3 and 4 colors, greedy assignment always works
 * @approach For each garden, pick first unused color among neighbors
 * @complexity Time: O(n + paths), Space: O(n + paths)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> gardenNoAdj(const int n, const vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (const auto& p : paths) {
            const int x = p[0] - 1, y = p[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> ans(n);
        bool used[5];
        for (int x = 0; x < n; ++x) {
            memset(used, false, sizeof(used));
            for (const int y : g[x]) {
                used[ans[y]] = true;
            }
            for (int c = 1; c < 5; ++c) {
                if (!used[c]) {
                    ans[x] = c;
                    break;
                }
            }
        }
        return ans;
    }
};
