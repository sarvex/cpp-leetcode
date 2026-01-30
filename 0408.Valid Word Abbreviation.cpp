/**
 * @brief Check if abbreviation is valid for given word
 * @intuition Numbers represent skipped characters, letters must match exactly
 * @approach Two-pointer traversal, parse numbers and compare characters
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto validWordAbbreviation(const std::string& word,
                                                     const std::string& abbr) -> bool {
        const auto m = static_cast<int>(word.size());
        const auto n = static_cast<int>(abbr.size());

        int i = 0;
        int j = 0;
        int x = 0;

        for (; i < m && j < n; ++j) {
            if (std::isdigit(abbr[j])) {
                if (abbr[j] == '0' && x == 0) {
                    return false;
                }
                x = x * 10 + (abbr[j] - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m || word[i] != abbr[j]) {
                    return false;
                }
                ++i;
            }
        }

        return i + x == m && j == n;
    }
};
