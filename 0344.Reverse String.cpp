/**
 * @brief Reverse string in-place using two pointers
 * @intuition Swap characters from both ends moving towards center
 * @approach Two pointers swapping until they meet
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    static void reverseString(std::vector<char>& s) {
        std::ranges::reverse(s);
    }
};
