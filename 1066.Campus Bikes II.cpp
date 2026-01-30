/**
 * @brief Bitmask DP for minimum total distance assignment
 * @intuition Assign workers to bikes minimizing total Manhattan distance
 * @approach f[i][j] = min cost to assign first i workers with bike mask j
 * @complexity Time: O(n * 2^m * m), Space: O(n * 2^m)
 */
class Solution final {
public:
    [[nodiscard]] static int assignBikes(
        const vector<vector<int>>& workers,
        const vector<vector<int>>& bikes) {
        
        const int n = workers.size(), m = bikes.size();
        int f[n + 1][1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (j >> k & 1) {
                        const int d = abs(workers[i - 1][0] - bikes[k][0]) + 
                                     abs(workers[i - 1][1] - bikes[k][1]);
                        f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return *min_element(f[n], f[n] + (1 << m));
    }
};
