/**
 * @brief Count beautiful arrangements using backtracking
 * @intuition At position i, try all numbers j where i divides j or j divides i
 * @approach Precompute valid numbers for each position based on divisibility.
 *           Backtrack through positions, trying each valid unused number.
 * @complexity Time: O(k) where k is number of valid permutations, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto countArrangement(int n) -> int {
        vector<bool> used(n + 1, false);
        unordered_map<int, vector<int>> validNums;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i % j == 0 || j % i == 0) {
                    validNums[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int pos) -> void {
            if (pos == n + 1) {
                ++ans;
                return;
            }
            for (int num : validNums[pos]) {
                if (!used[num]) {
                    used[num] = true;
                    dfs(pos + 1);
                    used[num] = false;
                }
            }
        };
        
        dfs(1);
        return ans;
    }
};
