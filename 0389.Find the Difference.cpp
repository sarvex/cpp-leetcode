/**
 * @brief Find the extra character added to shuffled string t
 * @intuition XOR all chars: pairs cancel, leaving the extra char
 * @approach Count chars in s, decrement for t, find negative count
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto findTheDifference(const std::string& s, const std::string& t) -> char {
        int cnt[26]{};

        for (const char c : s) {
            ++cnt[c - 'a'];
        }

        for (const char c : t) {
            if (--cnt[c - 'a'] < 0) {
                return c;
            }
        }

        return ' ';
    }
};
