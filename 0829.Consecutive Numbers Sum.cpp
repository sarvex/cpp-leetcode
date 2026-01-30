/**
 * @brief Count ways to express n as sum of consecutive positive integers
 * @intuition Sum of k consecutive starting at a: k*a + k*(k-1)/2 = n
 * @approach Rearrange to: 2n = k*(2a + k - 1). For each valid k, check if
 *           a = (2n/k - k + 1)/2 is a positive integer.
 * @complexity Time: O(sqrt(n)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto consecutiveNumbersSum(int n) -> int {
        n <<= 1;
        int ans = 0;
        
        for (int k = 1; k * (k + 1) <= n; ++k) {
            if (n % k == 0 && (n / k + 1 - k) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
