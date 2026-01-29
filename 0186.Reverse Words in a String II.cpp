/**
 * @brief Reverse words in character array in-place
 * @intuition Reverse each word, then reverse entire array
 * @approach Two-pass: reverse individual words, then reverse whole string
 * @complexity Time: O(n), Space: O(1)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    auto reverseWords(vector<char>& s) -> void {
        auto reverseRange = [&](int start, int end) {
            while (start < end) {
                std::swap(s[start++], s[end--]);
            }
        };
        
        const int n = static_cast<int>(s.size());
        
        // Reverse each word
        for (int wordStart = 0, i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                reverseRange(wordStart, i - 1);
                wordStart = i + 1;
            }
        }
        
        // Reverse entire string
        reverseRange(0, n - 1);
    }
};
