/**
 * @brief Find lexicographically smallest path with minimum cost
 * @intuition DP from end to start, then reconstruct path greedily
 * @approach Compute minimum cost backwards, then trace path forwards
 * @complexity Time: O(n * maxJump), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> cheapestJump(const vector<int>& coins, const int maxJump) {
        const int n = coins.size();
        vector<int> ans;
        
        if (coins[n - 1] == -1) {
            return ans;
        }
        
        constexpr int inf = 1 << 30;
        vector<int> f(n, inf);
        f[n - 1] = coins[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            if (coins[i] != -1) {
                for (int j = i + 1; j < min(n, i + maxJump + 1); ++j) {
                    f[i] = min(f[i], f[j] + coins[i]);
                }
            }
        }
        
        if (f[0] == inf) {
            return ans;
        }
        
        for (int i = 0, s = f[0]; i < n; ++i) {
            if (f[i] == s) {
                s -= coins[i];
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
