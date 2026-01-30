/**
 * @brief DP for counting valid playlists with song constraints
 * @intuition f[i][j] = playlists of length i using exactly j songs
 * @approach New song: multiply by remaining; repeat: only if >k songs played
 * @complexity Time: O(goal * n), Space: O(goal * n)
 */
class Solution final {
public:
    [[nodiscard]] static int numMusicPlaylists(const int n, const int goal, const int k) {
        constexpr int mod = 1e9 + 7;
        long long f[goal + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j - 1] * (n - j + 1);
                if (j > k) {
                    f[i][j] += f[i - 1][j] * (j - k);
                }
                f[i][j] %= mod;
            }
        }
        return static_cast<int>(f[goal][n]);
    }
};
