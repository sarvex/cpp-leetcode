/**
 * @brief Count valid permutations matching DI pattern
 * @intuition DP where f[i][j] = count of permutations of length i ending at relative position j
 * @approach For 'D', sum from current position up; for 'I', sum from 0 to current position
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int numPermsDISequence(const string& s) {
        constexpr int mod = 1e9 + 7;
        const int n = static_cast<int>(s.size());
        vector f(n + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'D') {
                for (int j = 0; j <= i; ++j) {
                    for (int k = j; k < i; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    for (int k = 0; k < j; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[n][j]) % mod;
        }
        return ans;
    }
};
