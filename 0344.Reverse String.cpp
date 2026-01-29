/**
 * @brief Reverse string in-place using two pointers
 * @intuition Swap characters from both ends moving towards center
 * @approach Two pointers swapping until they meet
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    void reverseString(std::vector<char>& s) const {
        for (int i = 0, j = static_cast<int>(s.size()) - 1; i < j; ++i, --j) {
            std::swap(s[i], s[j]);
        }
    }
};
