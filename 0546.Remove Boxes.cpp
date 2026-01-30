/**
 * @brief 3D DP with memoization for optimal box removal
 * @intuition Removing consecutive same-colored boxes gives (k+1)^2 points; merge distant same colors
 * @approach Use dfs(i,j,k) where k is count of boxes same color as boxes[j] following j
 * @complexity Time: O(n^4), Space: O(n^3)
 */
class Solution final {
public:
    [[nodiscard]] static int removeBoxes(vector<int>& boxes) {
        const int n = static_cast<int>(boxes.size());
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));
        
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i > j) {
                return 0;
            }
            
            while (i < j && boxes[j] == boxes[j - 1]) {
                --j;
                ++k;
            }
            
            if (memo[i][j][k]) {
                return memo[i][j][k];
            }
            
            int ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
            
            for (int h = i; h < j; ++h) {
                if (boxes[h] == boxes[j]) {
                    ans = max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1));
                }
            }
            
            return memo[i][j][k] = ans;
        };
        
        return dfs(0, n - 1, 0);
    }
};
