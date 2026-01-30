/**
 * @brief Check if string with '(', ')' and '*' (wildcard) is valid
 * @intuition Track min and max possible open parentheses count
 * @approach '*' can be '(', ')' or empty; track range of possible open counts
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool checkValidString(const string& s) {
        int lo = 0, hi = 0;
        
        for (const char c : s) {
            if (c == '(') {
                ++lo;
                ++hi;
            } else if (c == ')') {
                lo = max(0, lo - 1);
                --hi;
            } else {
                lo = max(0, lo - 1);
                ++hi;
            }
            if (hi < 0) {
                return false;
            }
        }
        return lo == 0;
    }
};
