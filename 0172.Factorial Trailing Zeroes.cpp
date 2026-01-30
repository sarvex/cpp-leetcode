/**
 * @brief Count trailing zeros in n factorial
 * @intuition Trailing zeros come from 10s, which come from 2*5 pairs; 5s are limiting
 * @approach Count multiples of 5, 25, 125, etc. in n
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto trailingZeroes(int n) -> int {
        int count = 0;
        
        while (n > 0) {
            n /= 5;
            count += n;
        }
        
        return count;
    }
};
