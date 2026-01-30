/**
 * @brief Find minimum cost to buy exactly needed items with special offers
 * @intuition DFS with memoization, try each offer and individual purchases
 * @approach Encode needs as bitmask, recursively try offers, cache results
 * @complexity Time: O(m * 2^(n*4)) where m is offers, Space: O(2^(n*4))
 */
class Solution final {
public:
    [[nodiscard]] static int shoppingOffers(const vector<int>& price, const vector<vector<int>>& special, const vector<int>& needs) {
        constexpr int bits = 4;
        const int n = needs.size();
        unordered_map<int, int> f;
        
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask |= needs[i] << (i * bits);
        }
        
        auto dfs = [&](this auto&& dfs, int cur) -> int {
            if (f.contains(cur)) {
                return f[cur];
            }
            
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += price[i] * ((cur >> (i * bits)) & 0xf);
            }
            
            for (const auto& offer : special) {
                int nxt = cur;
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    if (((cur >> (j * bits)) & 0xf) < offer[j]) {
                        ok = false;
                        break;
                    }
                    nxt -= offer[j] << (j * bits);
                }
                if (ok) {
                    ans = min(ans, offer[n] + dfs(nxt));
                }
            }
            
            f[cur] = ans;
            return ans;
        };
        
        return dfs(mask);
    }
};
