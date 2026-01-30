/**
 * @brief Check if substring can become palindrome with at most k character replacements
 * @intuition A string can be palindrome if at most one character has odd frequency; we can fix pairs
 * @approach Build prefix frequency counts. For each query, count odd-frequency characters.
 *           We need floor(odd/2) swaps; check if k is sufficient.
 * @complexity Time: O(n + q * 26), Space: O(n * 26) where q is query count
 */
class Solution final {
public:
    [[nodiscard]] static vector<bool> canMakePaliQueries(const string& s,
                                                         const vector<vector<int>>& queries) {
        const int n = s.size();
        vector<vector<int>> ss(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s[i - 1] - 'a']++;
        }
        vector<bool> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int x = 0;
            for (int j = 0; j < 26; ++j) {
                x += (ss[r + 1][j] - ss[l][j]) & 1;
            }
            ans.emplace_back(x / 2 <= k);
        }
        return ans;
    }
};
