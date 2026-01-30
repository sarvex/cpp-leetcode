/**
 * @brief Reverse only vowels in a string using two pointers
 * @intuition Find vowels from both ends and swap them
 * @approach Two pointers, skip non-vowels, swap vowels
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::string reverseVowels(std::string s) {
        static constexpr std::string_view vowels = "aeiouAEIOU";
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;
        
        while (i < j) {
            while (i < j && vowels.find(s[i]) == std::string_view::npos) {
                ++i;
            }
            while (i < j && vowels.find(s[j]) == std::string_view::npos) {
                --j;
            }
            if (i < j) {
                std::swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
