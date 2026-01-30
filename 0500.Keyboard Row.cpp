/**
 * @brief Find words that can be typed using one keyboard row
 * @intuition Map each letter to its row, check all letters in word share same row
 * @approach Precompute row for each letter, filter words with single row
 * @complexity Time: O(n * L) where L is average word length, Space: O(1)
 */
#include <cctype>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findWords(const std::vector<std::string>& words) const
        -> std::vector<std::string> {
        constexpr char rowMap[] = "12210111011122000010020202";
        std::vector<std::string> ans;

        for (const auto& word : words) {
            const char targetRow = rowMap[std::tolower(word[0]) - 'a'];
            bool sameRow = true;

            for (const char c : word) {
                if (rowMap[std::tolower(c) - 'a'] != targetRow) {
                    sameRow = false;
                    break;
                }
            }

            if (sameRow) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
