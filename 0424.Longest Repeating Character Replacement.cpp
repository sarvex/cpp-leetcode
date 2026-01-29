/**
 * @brief Find longest substring with at most k character replacements
 * @intuition Window is valid if length - maxFreq <= k (need to replace others)
 * @approach Sliding window, track max frequency, shrink when window invalid
 * @complexity Time: O(n) Space: O(1)
 */
#include <algorithm>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto characterReplacement(const std::string& s, int k) const -> int {
        int cnt[26]{};
        int l = 0;
        int mx = 0;
        const int n = static_cast<int>(s.length());

        for (int r = 0; r < n; ++r) {
            mx = std::max(mx, ++cnt[s[r] - 'A']);
            if (r - l + 1 - mx > k) {
                --cnt[s[l++] - 'A'];
            }
        }

        return n - l;
    }
};
