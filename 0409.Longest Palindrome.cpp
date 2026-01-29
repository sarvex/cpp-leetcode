/**
 * @brief Find length of longest palindrome that can be built from letters
 * @intuition Palindrome uses pairs of characters, plus one odd character in center
 * @approach Count character frequencies, sum pairs, add 1 if any odd count exists
 * @complexity Time: O(n) Space: O(1)
 */
#include <string>

class Solution final {
public:
    [[nodiscard]] auto longestPalindrome(const std::string& s) const -> int {
        int cnt[128]{};

        for (const char c : s) {
            ++cnt[static_cast<int>(c)];
        }

        int ans = 0;
        for (const int v : cnt) {
            ans += v / 2 * 2;
        }

        ans += ans < static_cast<int>(s.size()) ? 1 : 0;
        return ans;
    }
};
