/**
 * @brief Find all paths from source (0) to target (n-1) in DAG
 * @intuition DFS exploring all paths, backtrack after reaching target
 * @approach DFS with path tracking, add to result when reaching target
 * @complexity Time: O(2^n * n), Space: O(n) for recursion depth
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::vector<int>> allPathsSourceTarget(
            const std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> result;
        std::vector<int> path{0};
        const int target = static_cast<int>(graph.size()) - 1;
        
        auto dfs = [&](auto&& self, const int node) -> void {
            if (node == target) {
                result.push_back(path);
                return;
            }
            for (const int next : graph[node]) {
                path.push_back(next);
                self(self, next);
                path.pop_back();
            }
        };
        
        dfs(dfs, 0);
        return result;
    }
};
