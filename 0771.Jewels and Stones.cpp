/**
 * @brief Count jewel stones using hash set
 * @intuition Mark jewel characters, count occurrences in stones
 * @approach Use array as set for O(1) lookup
 * @complexity Time: O(j + s), Space: O(1) for fixed charset
 */
class Solution final {
public:
    [[nodiscard]] static int numJewelsInStones(const std::string& jewels, 
                                                const std::string& stones) {
        std::array<int, 128> isJewel{};
        for (const char c : jewels) {
            isJewel[c] = 1;
        }
        
        int count = 0;
        for (const char c : stones) {
            count += isJewel[c];
        }
        return count;
    }
};
