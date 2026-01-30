/**
 * @brief Bitmask DP to find minimum team covering all required skills
 * @intuition Use bitmask to represent skill coverage and find minimum people for full coverage
 * @approach Convert skills to bitmasks. Use DP where f[mask] is minimum people to achieve mask.
 *           Track which person was added and previous state for path reconstruction.
 * @complexity Time: O(2^m * n), Space: O(2^m) where m is skills count, n is people count
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> smallestSufficientTeam(const vector<string>& req_skills,
                                                            const vector<vector<string>>& people) {
        unordered_map<string, int> d;
        const int m = req_skills.size(), n = people.size();
        for (int i = 0; i < m; ++i) {
            d[req_skills[i]] = i;
        }
        vector<int> p(n, 0);
        for (int i = 0; i < n; ++i) {
            for (const auto& s : people[i]) {
                p[i] |= 1 << d[s];
            }
        }
        vector<int> f(1 << m, 0x3f3f3f3f);
        vector<int> g(1 << m);
        vector<int> h(1 << m);
        f[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (f[i] == 0x3f3f3f3f) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (f[i] + 1 < f[i | p[j]]) {
                    f[i | p[j]] = f[i] + 1;
                    g[i | p[j]] = j;
                    h[i | p[j]] = i;
                }
            }
        }
        vector<int> ans;
        for (int i = (1 << m) - 1; i; i = h[i]) {
            ans.push_back(g[i]);
        }
        return ans;
    }
};
