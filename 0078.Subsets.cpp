/**
 * @brief Backtracking to generate all subsets (power set)
 * @intuition Each element can either be included or excluded from a subset
 * @approach Use DFS exploring both choices for each element; collect subset at leaf
 * @complexity Time: O(2^n * n), Space: O(n) recursion depth
 */
class Solution final {
public:
    [[nodiscard]] static auto subsets(const vector<int>& nums) -> vector<vector<int>> {
        vector<vector<int>> result;
        vector<int> current;
        const int n = static_cast<int>(nums.size());
        
        auto dfs = [&](this auto&& dfs, const int i) -> void {
            if (i == n) {
                result.push_back(current);
                return;
            }
            dfs(i + 1);
            current.push_back(nums[i]);
            dfs(i + 1);
            current.pop_back();
        };
        
        dfs(0);
        return result;
    }
};
