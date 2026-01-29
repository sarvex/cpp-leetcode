/**
 * @brief Compress array in-place, return new length
 * @intuition Group consecutive chars, write char and count if > 1
 * @approach Two pointers: read groups, write compressed output
 * @complexity Time: O(n) Space: O(1)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto compress(std::vector<char>& chars) const -> int {
        int k = 0;
        const int n = static_cast<int>(chars.size());

        for (int i = 0, j = 1; i < n;) {
            while (j < n && chars[j] == chars[i]) {
                ++j;
            }

            chars[k++] = chars[i];

            if (j - i > 1) {
                for (const char c : std::to_string(j - i)) {
                    chars[k++] = c;
                }
            }

            i = j;
        }

        return k;
    }
};
