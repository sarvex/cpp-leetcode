/**
 * @brief Check if string can be palindrome by deleting at most one character
 * @intuition Find first mismatch, try deleting either character
 * @approach Two pointers from ends; at mismatch, check both skip options
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool validPalindrome(const string& s) {
        auto check = [&](int i, int j) {
            for (; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j) || check(i, j - 1);
            }
        }
        return true;
    }
};
