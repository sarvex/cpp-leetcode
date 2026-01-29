/**
 * @brief Backtracking to generate all k-combinations from 1 to n
 * @intuition Explore all possibilities by including or excluding each number
 * @approach Use DFS with backtracking; for each position, try including the current
 *           number then backtrack, creating all valid combinations of size k
 * @complexity Time: O(C(n,k) * k), Space: O(k) recursion depth
 */
class Solution final {
public:
    [[nodiscard]] static auto combine(const int n, const int k) -> vector<vector<int>> {
        vector<vector<int>> result;
        vector<int> current;
        
        auto dfs = [&](this auto&& dfs, const int i) -> void {
            if (current.size() == static_cast<size_t>(k)) {
                result.emplace_back(current);
                return;
            }
            if (i > n) {
                return;
            }
            current.emplace_back(i);
            dfs(i + 1);
            current.pop_back();
            dfs(i + 1);
        };
        
        dfs(1);
        return result;
    }
};
