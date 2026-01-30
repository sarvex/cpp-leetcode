/**
 * @brief Check if number equals sum of its proper divisors
 * @intuition Sum divisors up to sqrt(n), adding both i and n/i when applicable
 * @approach Start with sum=1 (all numbers have 1 as divisor). For each i from 2 to sqrt(n),
 *           if i divides n, add i and n/i (if different) to sum. Compare final sum with n.
 * @complexity Time: O(sqrt(n)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr auto checkPerfectNumber(int num) -> bool {
        if (num == 1) return false;
        
        int sum = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};
