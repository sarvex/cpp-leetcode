/**
 * @brief Hierholzer's algorithm for Eulerian path reconstruction
 * @intuition Find path using all tickets exactly once, lexicographically smallest
 * @approach DFS with backtracking, pop visited edges, reverse final path
 * @complexity Time: O(E log E), Space: O(E)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::string> findItinerary(
        std::vector<std::vector<std::string>>& tickets) {
        
        std::ranges::sort(tickets, std::greater<>());
        std::unordered_map<std::string, std::vector<std::string>> graph;
        
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        std::vector<std::string> ans;
        auto dfs = [&](this auto&& dfs, std::string& from) -> void {
            while (!graph[from].empty()) {
                std::string to = graph[from].back();
                graph[from].pop_back();
                dfs(to);
            }
            ans.emplace_back(from);
        };
        
        std::string start = "JFK";
        dfs(start);
        std::ranges::reverse(ans);
        return ans;
    }
};
