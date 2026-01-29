/**
 * @brief Check if two strings are exactly one edit apart
 * @intuition One edit means insert, delete, or replace exactly one character
 * @approach Compare char by char, handle length differences appropriately
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto isOneEditDistance(const std::string& s, const std::string& t) -> bool {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(t.size());
        
        if (m < n) {
            return isOneEditDistance(t, s);
        }
        
        if (m - n > 1) {
            return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (m == n) {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                return s.substr(i + 1) == t.substr(i);
            }
        }
        
        return m == n + 1;
    }
};
