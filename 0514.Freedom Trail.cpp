/**
 * @brief Dynamic programming for minimum rotation steps on ring dial
 * @intuition For each key character, find optimal ring position minimizing total rotations
 * @approach DP where f[i][j] = min steps to spell first i characters with ring at position j.
 *           Precompute positions of each character. Transition considers all valid positions.
 * @complexity Time: O(m * n^2), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findRotateSteps(const string& ring, const string& key) -> int {
        const int m = static_cast<int>(key.size());
        const int n = static_cast<int>(ring.size());
        
        array<vector<int>, 26> pos;
        for (int j = 0; j < n; ++j) {
            pos[ring[j] - 'a'].push_back(j);
        }
        
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        
        for (int j : pos[key[0] - 'a']) {
            f[0][j] = min(j, n - j) + 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j : pos[key[i] - 'a']) {
                for (int k : pos[key[i - 1] - 'a']) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        
        int ans = INT_MAX;
        for (int j : pos[key[m - 1] - 'a']) {
            ans = min(ans, f[m - 1][j]);
        }
        return ans;
    }
};
