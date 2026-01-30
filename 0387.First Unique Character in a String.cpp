/**
 * @brief Find index of first non-repeating character in string
 * @intuition Count all characters first, then find first with count 1
 * @approach Two-pass: count frequencies, then find first unique
 * @complexity Time: O(n), Space: O(1) - fixed 26 char alphabet
 */
class Solution final {
public:
    [[nodiscard]] static auto firstUniqChar(const std::string& s) -> int {
        int cnt[26]{};

        for (const char c : s) {
            ++cnt[c - 'a'];
        }

        const auto n = static_cast<int>(s.size());
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
