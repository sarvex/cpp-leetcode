/**
 * @brief Make largest special string by swapping special substrings
 * @intuition Special strings are like balanced parentheses; recursively sort segments
 * @approach Split into special substrings, recursively process inner parts, sort descending
 * @complexity Time: O(n^2 log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] std::string makeLargestSpecial(const std::string& s) {
        if (s.empty()) return s;
        
        std::vector<std::string> parts;
        int balance = 0;
        
        for (size_t i = 0, j = 0; i < s.size(); ++i) {
            balance += (s[i] == '1') ? 1 : -1;
            if (balance == 0) {
                parts.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        
        std::ranges::sort(parts, std::greater<>());
        std::string result;
        for (const auto& part : parts) {
            result += part;
        }
        return result;
    }
};
