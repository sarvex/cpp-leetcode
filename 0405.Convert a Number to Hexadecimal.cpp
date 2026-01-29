/**
 * @brief Convert integer to hexadecimal string (two's complement for negatives)
 * @intuition Extract 4 bits at a time from most significant to least significant
 * @approach Process each nibble, skip leading zeros
 * @complexity Time: O(1) - fixed 8 iterations Space: O(1)
 */
#include <string>

class Solution final {
public:
    [[nodiscard]] auto toHex(int num) const -> std::string {
        if (num == 0) {
            return "0";
        }

        std::string s;
        for (int i = 7; i >= 0; --i) {
            const int x = (num >> (4 * i)) & 0xf;
            if (!s.empty() || x != 0) {
                const char c = x < 10 ? static_cast<char>(x + '0') : static_cast<char>(x - 10 + 'a');
                s += c;
            }
        }

        return s;
    }
};
