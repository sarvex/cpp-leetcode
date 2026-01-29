/**
 * @brief Check if two strings are exactly one edit apart
 * @intuition One edit means insert, delete, or replace exactly one character
 * @approach Compare char by char, handle length differences appropriately
 * @complexity Time: O(n), Space: O(1)
 */

#include <string>

using std::string;

class Solution final {
public:
    [[nodiscard]] auto isOneEditDistance(const string& s, const string& t) const -> bool {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(t.size());
        
        // Ensure s is the shorter string
        if (m < n) {
            return isOneEditDistance(t, s);
        }
        
        // Length difference > 1 means more than one edit
        if (m - n > 1) {
            return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (m == n) {
                    // Replace: rest must be equal
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                // Delete from s: s[i+1:] must equal t[i:]
                return s.substr(i + 1) == t.substr(i);
            }
        }
        
        // All chars matched, valid only if s has exactly one extra char
        return m == n + 1;
    }
};
