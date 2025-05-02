/**
 * @brief Returns the length of the last word in a string using reverse iterators and STL algorithms.
 * @intuition: Skip trailing spaces, then count characters until the next space or beginning.
 * @approach: Use std::string_view, reverse iterators, std::find_if, and std::distance for clarity and performance.
 * @complexity: O(N) time, O(1) space.
 */
#include <string_view>
#include <algorithm>
#include <cctype>

class Solution {
public:
    [[nodiscard]] static constexpr int lengthOfLastWord(std::string_view s) noexcept {
        // Remove trailing spaces
        auto rbegin = s.rbegin(), rend = s.rend();
        rbegin = std::find_if(rbegin, rend, [](char ch) {
            return !std::isspace(static_cast<unsigned char>(ch));
        });
        // Count characters until next space or start
        auto word_end = std::find_if(rbegin, rend, [](char ch) {
            return std::isspace(static_cast<unsigned char>(ch));
        });
        return static_cast<int>(std::distance(rbegin, word_end));
    }
};
