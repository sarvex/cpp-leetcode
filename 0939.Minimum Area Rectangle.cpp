/**
 * @brief Find minimum area rectangle from points
 * @intuition For each pair of y-coordinates, track previous x with same pair
 * @approach Group points by x; for each pair of points with same x, lookup previous
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> d;
        for (const auto& p : points) {
            const int x = p[0], y = p[1];
            d[x].emplace_back(y);
        }
        unordered_map<int, int> pos;
        int ans = 1 << 30;
        for (auto& [x, ys] : d) {
            ranges::sort(ys);
            const int n = static_cast<int>(ys.size());
            for (int i = 0; i < n; ++i) {
                const int y1 = ys[i];
                for (int j = i + 1; j < n; ++j) {
                    const int y2 = ys[j];
                    const int p = y1 * 40001 + y2;
                    if (pos.contains(p)) {
                        ans = min(ans, (x - pos[p]) * (y2 - y1));
                    }
                    pos[p] = x;
                }
            }
        }
        return ans == 1 << 30 ? 0 : ans;
    }
};
