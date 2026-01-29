/**
 * @brief Check if string can be formed by repeating a substring
 * @intuition If s is made of pattern p, then s+s contains s at non-edge position
 * @approach Search s in (s+s) starting from index 1, check if found before len(s)
 * @complexity Time: O(n) Space: O(n)
 */
#include <string>

class Solution final {
public:
    [[nodiscard]] auto repeatedSubstringPattern(const std::string& s) const -> bool {
        return (s + s).find(s, 1) < s.size();
    }
};
