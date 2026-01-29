/**
 * @brief Memoized recursion to check if s2 is a scrambled string of s1
 * @intuition A scrambled string can have its parts swapped or kept in place at any split
 * @approach Try all split points; check both swapped and non-swapped configurations
 * @complexity Time: O(n^4), Space: O(n^3)
 */
class Solution final {
public:
    [[nodiscard]] static auto isScramble(const string& s1, const string& s2) -> bool {
        const int n = static_cast<int>(s1.size());
        vector memo(n, vector(n, vector<int>(n + 1, -1)));
        
        auto dfs = [&](this auto&& dfs, const int i, const int j, const int k) -> bool {
            if (memo[i][j][k] != -1) {
                return memo[i][j][k] == 1;
            }
            if (k == 1) {
                return s1[i] == s2[j];
            }
            
            for (int h = 1; h < k; ++h) {
                if (dfs(i, j, h) && dfs(i + h, j + h, k - h)) {
                    memo[i][j][k] = 1;
                    return true;
                }
                if (dfs(i + h, j, k - h) && dfs(i, j + k - h, h)) {
                    memo[i][j][k] = 1;
                    return true;
                }
            }
            
            memo[i][j][k] = 0;
            return false;
        };
        
        return dfs(0, 0, n);
    }
};
