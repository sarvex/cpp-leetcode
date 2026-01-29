/**
 * @brief Count unique substrings of s that are in wraparound "abcd...xyz"
 * @intuition Consecutive substrings ending at each letter - track longest per ending char
 * @approach For each char, track max length of consecutive sequence ending there
 * @complexity Time: O(n) Space: O(1)
 */
#include <algorithm>
#include <numeric>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto findSubstringInWraproundString(const std::string& s) const -> int {
        int f[26]{};
        const int n = static_cast<int>(s.length());

        for (int i = 0, k = 0; i < n; ++i) {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
                ++k;
            } else {
                k = 1;
            }
            f[s[i] - 'a'] = std::max(f[s[i] - 'a'], k);
        }

        return std::accumulate(std::begin(f), std::end(f), 0);
    }
};
