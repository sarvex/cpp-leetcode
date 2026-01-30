/**
 * @brief Open lock with minimum turns using BFS
 * @intuition Each state has 8 neighbors (4 digits × 2 directions), find shortest path
 * @approach BFS from "0000", generate neighbors, avoid deadends
 * @complexity Time: O(10^4 + d), Space: O(10^4 + d) where d is deadends count
 */
class Solution final {
public:
    [[nodiscard]] static int openLock(const std::vector<std::string>& deadends, 
                                       const std::string& target) {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        if (visited.contains("0000")) return -1;
        if (target == "0000") return 0;
        
        std::queue<std::string> queue;
        queue.push("0000");
        visited.insert("0000");
        int steps = 0;
        
        while (!queue.empty()) {
            ++steps;
            for (int sz = static_cast<int>(queue.size()); sz > 0; --sz) {
                std::string current = queue.front();
                queue.pop();
                for (const auto& next : getNeighbors(current)) {
                    if (next == target) return steps;
                    if (!visited.contains(next)) {
                        queue.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }

private:
    [[nodiscard]] static std::vector<std::string> getNeighbors(std::string& state) {
        std::vector<std::string> neighbors;
        for (int i = 0; i < 4; ++i) {
            const char c = state[i];
            state[i] = (c == '0') ? '9' : static_cast<char>(c - 1);
            neighbors.push_back(state);
            state[i] = (c == '9') ? '0' : static_cast<char>(c + 1);
            neighbors.push_back(state);
            state[i] = c;
        }
        return neighbors;
    }
};
