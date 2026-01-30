/**
 * @brief Check if last character is one-bit
 * @intuition Parse from left; 1 always starts 2-bit char, 0 is 1-bit
 * @approach Greedy traversal: skip 1 or 2 positions based on current bit
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isOneBitCharacter(const std::vector<int>& bits) {
        int i = 0;
        const int n = static_cast<int>(bits.size());
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};
