/**
 * @brief Check if number equals sum of its digits raised to power of digit count
 * @intuition Armstrong number: sum of each digit^(number of digits) equals the number itself
 * @approach Count digits, then sum each digit raised to that power. Compare with original.
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isArmstrong(const int n) {
        const int k = to_string(n).size();
        int s = 0;
        for (int x = n; x; x /= 10) {
            s += pow(x % 10, k);
        }
        return s == n;
    }
};
