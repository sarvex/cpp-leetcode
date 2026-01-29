/**
 * @brief Convert Excel column title to number (base-26 conversion)
 * @intuition Each character represents a digit in base-26 (A=1, B=2, ..., Z=26)
 * @approach Process left to right, multiply by 26 and add current digit
 * @complexity Time: O(n), Space: O(1)
 */

#include <string>

using std::string;

class Solution final {
public:
    [[nodiscard]] auto titleToNumber(const string& columnTitle) const -> int {
        int result = 0;
        
        for (const char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        
        return result;
    }
};
