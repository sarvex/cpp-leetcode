/**
 * @brief Reverse words in string using in-place reversal
 * @intuition Reverse each word, then reverse entire string
 * @approach Clean extra spaces, reverse words individually, reverse whole string
 * @complexity Time: O(n), Space: O(1) in-place
 */

#include <algorithm>
#include <string>

using std::string;

class Solution final {
public:
    [[nodiscard]] static auto reverseWords(string s) -> string {
        int writeIdx = 0;
        const int n = static_cast<int>(s.size());

        for (int readIdx = 0; readIdx < n; ++readIdx) {
            // Skip leading/extra spaces
            while (readIdx < n && s[readIdx] == ' ') {
                ++readIdx;
            }

            if (readIdx < n) {
                // Add space between words
                if (writeIdx != 0) {
                    s[writeIdx++] = ' ';
                }

                // Copy word and reverse it
                const int wordStart = writeIdx;
                while (readIdx < n && s[readIdx] != ' ') {
                    s[writeIdx++] = s[readIdx++];
                }
                std::reverse(s.begin() + wordStart, s.begin() + writeIdx);
            }
        }

        s.erase(s.begin() + writeIdx, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};
