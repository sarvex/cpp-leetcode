/**
 * @brief Limited BFS to check if source and target can escape blocked area
 * @intuition Max blocked area with n blocks is n*(n-1)/2; if BFS exceeds this, escape possible
 * @approach DFS from both ends; if either reaches other or escapes blocked region, return true
 * @complexity Time: O(blocked^2), Space: O(blocked^2)
 */
class Solution final {
public:
    [[nodiscard]] static bool isEscapePossible(
        const vector<vector<int>>& blocked,
        const vector<int>& source,
        const vector<int>& target) {
        
        constexpr int n = 1e6;
        const int m = blocked.size() * blocked.size() / 2;
        using ll = long long;
        unordered_set<ll> s;
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        
        auto f = [](const int i, const int j) {
            return static_cast<ll>(i) * n + j;
        };
        
        for (const auto& b : blocked) {
            s.insert(f(b[0], b[1]));
        }
        
        const int sx = source[0], sy = source[1];
        const int tx = target[0], ty = target[1];
        unordered_set<ll> vis1, vis2;
        
        auto dfs = [&](this auto&& dfs, int sx, int sy, int tx, int ty, unordered_set<ll>& vis) -> bool {
            vis.insert(f(sx, sy));
            if (vis.size() > static_cast<size_t>(m)) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                const int x = sx + dirs[k], y = sy + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x == tx && y == ty) {
                        return true;
                    }
                    auto key = f(x, y);
                    if (!s.contains(key) && !vis.contains(key) && dfs(x, y, tx, ty, vis)) {
                        return true;
                    }
                }
            }
            return false;
        };
        
        return dfs(sx, sy, tx, ty, vis1) && dfs(tx, ty, sx, sy, vis2);
    }
};
