/**
 * @brief DP to maximize vacation days over K weeks with flight constraints
 * @intuition State: week k at city j; transition considers flights from previous week
 * @approach f[k][j] = max vacation ending week k at city j; update considering all incoming flights
 * @complexity Time: O(K * n^2), Space: O(K * n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxVacationDays(const vector<vector<int>>& flights,
                                              const vector<vector<int>>& days) {
        const int n = static_cast<int>(flights.size());
        const int K = static_cast<int>(days[0].size());
        
        int f[K + 1][n];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < n; ++j) {
                f[k][j] = f[k - 1][j];
                for (int i = 0; i < n; ++i) {
                    if (flights[i][j] == 1) {
                        f[k][j] = max(f[k][j], f[k - 1][i]);
                    }
                }
                f[k][j] += days[j][k - 1];
            }
        }
        
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, f[K][j]);
        }
        
        return ans;
    }
};
