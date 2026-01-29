/**
 * @brief Memoized DFS to check if s3 is interleaving of s1 and s2
 * @intuition s3[k] must match either s1[i] or s2[j] at each position
 * @approach DFS with memoization; try matching from s1 or s2 at each step
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto isInterleave(const string& s1, const string& s2, const string& s3) -> bool {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());
        
        if (m + n != static_cast<int>(s3.size())) {
            return false;
        }
        
        vector memo(m + 1, vector<int>(n + 1, -1));
        
        auto dfs = [&](this auto&& dfs, const int i, const int j) -> bool {
            if (i >= m && j >= n) {
                return true;
            }
            if (memo[i][j] != -1) {
                return memo[i][j] == 1;
            }
            
            memo[i][j] = 0;
            const int k = i + j;
            
            if (i < m && s1[i] == s3[k] && dfs(i + 1, j)) {
                memo[i][j] = 1;
            }
            if (memo[i][j] == 0 && j < n && s2[j] == s3[k] && dfs(i, j + 1)) {
                memo[i][j] = 1;
            }
            
            return memo[i][j] == 1;
        };
        
        return dfs(0, 0);
    }
};
