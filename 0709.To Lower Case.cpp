/**
 * @brief Convert string to lowercase using bit manipulation
 * @intuition ASCII uppercase differs from lowercase by bit 5 (value 32)
 * @approach OR with 32 sets bit 5, converting A-Z to a-z
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::string toLowerCase(std::string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c |= 32;
            }
        }
        return s;
    }
};
