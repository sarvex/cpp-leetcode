/**
 * @brief Remove all vowels from a string
 * @intuition Filter out characters that are vowels (a, e, i, o, u)
 * @approach Iterate through string and build result with only consonants
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string removeVowels(const string& s) {
        string ans;
        for (char c : s) {
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                ans += c;
            }
        }
        return ans;
    }
};
