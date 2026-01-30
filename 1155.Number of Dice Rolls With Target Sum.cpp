/**
 * @brief Count ways to roll n dice with k faces to reach target sum
 * @intuition DP where each state depends on possible face values of one die
 * @approach Use f[i][j] for ways to get sum j with i dice. For each die, iterate possible
 *           face values 1 to k and accumulate from previous state.
 * @complexity Time: O(n * target * k), Space: O(n * target)
 */
class Solution final {
public:
    [[nodiscard]] static int numRollsToTarget(const int n, const int k, const int target) {
        constexpr int mod = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(target, i * k); ++j) {
                for (int h = 1; h <= min(j, k); ++h) {
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod;
                }
            }
        }
        return f[n][target];
    }
};
