/**
 * @brief Reverse only vowels in a string using two pointers
 * @intuition Find vowels from both ends and swap them
 * @approach Two pointers, skip non-vowels, swap vowels
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <string>
#include <unordered_set>

class Solution final {
public:
    [[nodiscard]] std::string reverseVowels(std::string s) const {
        static const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 
                                                         'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;
        
        while (i < j) {
            while (i < j && !vowels.contains(s[i])) {
                ++i;
            }
            while (i < j && !vowels.contains(s[j])) {
                --j;
            }
            if (i < j) {
                std::swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
