/**
 * @brief Interval DP with piles merging optimization
 * @intuition Merge K piles at a time; need (n-1) % (K-1) == 0 for valid solution
 * @approach Use 3D DP where f[i][j][k] = min cost to merge stones[i..j] into k piles.
 *           For each interval, try all split points and accumulate merge costs.
 * @complexity Time: O(n^3 * K), Space: O(n^2 * K)
 */
class Solution final {
public:
    [[nodiscard]] static int mergeStones(const std::vector<int>& stones, const int K) {
        const int n = static_cast<int>(stones.size());
        if ((n - 1) % (K - 1)) {
            return -1;
        }
        std::vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + stones[i - 1];
        }
        constexpr int INF = 0x3f3f3f3f;
        std::vector f(n + 1, std::vector(n + 1, std::vector<int>(K + 1, INF)));
        for (int i = 1; i <= n; ++i) {
            f[i][i][1] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                const int j = i + l - 1;
                for (int k = 1; k <= K; ++k) {
                    for (int h = i; h < j; ++h) {
                        f[i][j][k] = std::min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1];
            }
        }
        return f[1][n][1];
    }
};
