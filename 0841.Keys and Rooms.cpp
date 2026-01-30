/**
 * @brief DFS traversal to check if all rooms are reachable from room 0
 * @intuition Starting from room 0, recursively visit rooms using found keys
 * @approach DFS from room 0, marking visited rooms. Count visited rooms and
 *           compare with total. All rooms reachable iff count equals n.
 * @complexity Time: O(n + k) where k is total keys, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto canVisitAllRooms(
        const std::vector<std::vector<int>>& rooms) -> bool {
        const int n = static_cast<int>(rooms.size());
        int cnt = 0;
        std::vector<bool> vis(n, false);
        
        auto dfs = [&](auto&& self, int i) -> void {
            if (vis[i]) return;
            vis[i] = true;
            ++cnt;
            for (const int j : rooms[i]) {
                self(self, j);
            }
        };
        
        dfs(dfs, 0);
        return cnt == n;
    }
};
