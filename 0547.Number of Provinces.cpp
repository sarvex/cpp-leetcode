/**
 * @brief Count connected components using DFS
 * @intuition Each province is a connected component in the adjacency matrix graph
 * @approach DFS from each unvisited city, marking all reachable cities; count DFS calls
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = static_cast<int>(isConnected.size());
        int ans = 0;
        vector<bool> visited(n);
        
        auto dfs = [&](this auto&& dfs, int i) -> void {
            visited[i] = true;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && isConnected[i][j]) {
                    dfs(j);
                }
            }
        };
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                ++ans;
            }
        }
        
        return ans;
    }
};
