/**
 * @brief Validate capital letter usage in word
 * @intuition Valid: all caps, all lower, or only first cap
 * @approach Count uppercase letters. Valid if count is 0, equals length, or equals 1 with first uppercase.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto detectCapitalUse(const string& word) -> bool {
        const auto cnt = count_if(word.begin(), word.end(), [](char c) { 
            return isupper(c); 
        });
        return cnt == 0 || cnt == static_cast<int>(word.length()) || 
               (cnt == 1 && isupper(word[0]));
    }
};
