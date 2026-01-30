/**
 * @brief Count substrings containing only one distinct character
 * @intuition A run of k identical characters contributes k*(k+1)/2 substrings
 * @approach Find consecutive runs of same characters. For each run of length L,
 *           add L*(L+1)/2 to answer (arithmetic series of substring counts).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int countLetters(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            ans += (1 + j - i) * (j - i) / 2;
            i = j;
        }
        return ans;
    }
};
