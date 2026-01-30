/**
 * @brief Check if number is a power of three
 * @intuition Repeatedly divide by 3 while divisible
 * @approach Loop dividing by 3, check if result is 1
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr bool isPowerOfThree(int n) {
        while (n > 2) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};
