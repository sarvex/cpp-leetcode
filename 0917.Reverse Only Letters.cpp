/**
 * @brief Two-pointer reversal skipping non-letters
 * @intuition Swap only letter characters, skip others
 * @approach Two pointers from ends; advance past non-letters, swap letters
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string reverseOnlyLetters(string s) {
        int i = 0, j = static_cast<int>(s.size()) - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
