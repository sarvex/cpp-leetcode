/**
 * @brief Check if string is palindrome considering only alphanumeric characters
 * @intuition Two pointers from both ends, skip non-alphanumeric, compare lowercase
 * @approach Move pointers inward, comparing valid characters case-insensitively
 * @complexity Time: O(n), Space: O(1)
 */

#include <cctype>
#include <string>

using std::string;

class Solution final {
public:
    [[nodiscard]] auto isPalindrome(const string& s) const -> bool {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;
        
        while (left < right) {
            if (!std::isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
            } else if (!std::isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
            } else if (std::tolower(static_cast<unsigned char>(s[left])) != 
                       std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
