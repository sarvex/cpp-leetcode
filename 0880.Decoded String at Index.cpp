/**
 * @brief Work backwards to find kth character without full expansion
 * @intuition Track total length; work backwards reducing k until finding answer
 * @approach First compute total decoded length. Then iterate backwards: for digits,
 *           divide length; for letters, check if k points to this char (with modulo).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto decodeAtIndex(const std::string& s, int k)
        -> std::string {
        long long m = 0;
        
        for (const char c : s) {
            if (std::isdigit(c)) {
                m *= (c - '0');
            } else {
                ++m;
            }
        }
        
        for (int i = static_cast<int>(s.size()) - 1;; --i) {
            k %= m;
            if (k == 0 && std::isalpha(s[i])) {
                return std::string(1, s[i]);
            }
            if (std::isdigit(s[i])) {
                m /= (s[i] - '0');
            } else {
                --m;
            }
        }
    }
};
