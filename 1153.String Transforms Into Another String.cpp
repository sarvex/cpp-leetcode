/**
 * @brief Check if string can be transformed to another by character replacements
 * @intuition Each source character can only map to one target character; need spare character for cycles
 * @approach Verify each source character maps consistently to one target character. If target uses all
 *           26 characters and strings differ, transformation is impossible (no spare character for cycles).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool canConvert(const string& str1, const string& str2) {
        if (str1 == str2) {
            return true;
        }
        int cnt[26]{};
        int m = 0;
        for (char c : str2) {
            if (++cnt[c - 'a'] == 1) {
                ++m;
            }
        }
        if (m == 26) {
            return false;
        }
        int d[26]{};
        for (int i = 0; i < str1.size(); ++i) {
            int a = str1[i] - 'a';
            int b = str2[i] - 'a';
            if (d[a] == 0) {
                d[a] = b + 1;
            } else if (d[a] != b + 1) {
                return false;
            }
        }
        return true;
    }
};
