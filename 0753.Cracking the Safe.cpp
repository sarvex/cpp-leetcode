/**
 * @brief Generate de Bruijn sequence for safe cracking
 * @intuition Find Eulerian path through state graph where edges are k-digit sequences
 * @approach Hierholzer's algorithm: DFS through all edges exactly once
 * @complexity Time: O(k^n), Space: O(k^n)
 */
class Solution final {
public:
    [[nodiscard]] static std::string crackSafe(const int n, const int k) {
        std::unordered_set<int> visited;
        const int mod = static_cast<int>(std::pow(10, n - 1));
        std::string result;
        
        auto dfs = [&](auto&& self, int node) -> void {
            for (int digit = 0; digit < k; ++digit) {
                const int edge = node * 10 + digit;
                if (!visited.contains(edge)) {
                    visited.insert(edge);
                    self(self, edge % mod);
                    result += static_cast<char>('0' + digit);
                }
            }
        };
        
        dfs(dfs, 0);
        result += std::string(n - 1, '0');
        return result;
    }
};
