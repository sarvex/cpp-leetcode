/**
 * @brief Sliding window with character frequency tracking
 * @intuition Use two pointers to maintain a window containing all characters of t
 * @approach Track character frequencies with arrays; expand right to include chars,
 *           contract left to minimize window while maintaining validity
 * @complexity Time: O(m + n), Space: O(1) - fixed size arrays for ASCII
 */
class Solution final {
public:
    [[nodiscard]] static auto minWindow(const string& s, const string& t) -> string {
        array<int, 128> need{};
        array<int, 128> window{};
        
        for (const char c : t) {
            ++need[c];
        }

        const int m = static_cast<int>(s.length());
        const int n = static_cast<int>(t.length());
        int k = -1;
        int minLen = m + 1;
        int cnt = 0;

        for (int left = 0, right = 0; right < m; ++right) {
            const char c = s[right];
            if (++window[c] <= need[c]) {
                ++cnt;
            }

            while (cnt == n) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    k = left;
                }

                const char leftChar = s[left];
                if (window[leftChar] <= need[leftChar]) {
                    --cnt;
                }
                --window[leftChar];
                ++left;
            }
        }

        return k < 0 ? "" : s.substr(k, minLen);
    }
};
