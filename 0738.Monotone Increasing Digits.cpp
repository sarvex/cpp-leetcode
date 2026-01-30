/**
 * @brief Largest monotone increasing digits <= n
 * @intuition Find first decreasing digit, decrement and fill rest with 9s
 * @approach Scan for violation, backtrack while needed, fill trailing 9s
 * @complexity Time: O(log n), Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static int monotoneIncreasingDigits(const int n) {
        std::string s = std::to_string(n);
        int i = 1;
        
        while (i < static_cast<int>(s.size()) && s[i - 1] <= s[i]) {
            ++i;
        }
        
        if (i < static_cast<int>(s.size())) {
            while (i > 0 && s[i - 1] > s[i]) {
                --s[i - 1];
                --i;
            }
            ++i;
            while (i < static_cast<int>(s.size())) {
                s[i++] = '9';
            }
        }
        
        return std::stoi(s);
    }
};
