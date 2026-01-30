/**
 * @brief Find lexicographically largest suffix of string
 * @intuition Compare suffixes starting at different positions using two-pointer technique
 * @approach Use optimized comparison: track two candidate starting positions and comparison offset.
 *           Skip forward efficiently when mismatch found.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string lastSubstring(const string& s) {
        const int n = s.size();
        int i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] < s[j + k]) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
