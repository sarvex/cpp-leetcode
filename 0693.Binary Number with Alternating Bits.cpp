/**
 * @brief Check if binary representation has alternating bits
 * @intuition Compare each bit with previous bit
 * @approach Extract bits one by one, ensure each differs from previous
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n) {
            const int curr = n & 1;
            if (prev == curr) {
                return false;
            }
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};
