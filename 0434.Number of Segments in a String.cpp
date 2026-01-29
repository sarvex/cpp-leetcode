/**
 * @brief Count segments (contiguous non-space characters) in string
 * @intuition Use istringstream to extract words separated by whitespace
 * @approach Stream extraction skips whitespace automatically
 * @complexity Time: O(n) Space: O(n)
 */
#include <sstream>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto countSegments(const std::string& s) const -> int {
        int ans = 0;
        std::istringstream ss(s);
        std::string word;

        while (ss >> word) {
            ++ans;
        }

        return ans;
    }
};
