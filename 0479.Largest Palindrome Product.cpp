/**
 * @brief Find largest palindrome made from product of two n-digit numbers
 * @intuition Generate palindromes from largest, check if divisible by n-digit number
 * @approach Build palindrome by mirroring first half, verify factorization
 * @complexity Time: O(10^n), Space: O(1)
 */
#include <cmath>

class Solution final {
public:
    [[nodiscard]] auto largestPalindrome(int n) const -> int {
        const int mx = static_cast<int>(std::pow(10, n)) - 1;

        for (int a = mx; a > mx / 10; --a) {
            long long x = a;
            for (int b = a; b > 0; b /= 10) {
                x = x * 10 + b % 10;
            }

            for (long long t = mx; t * t >= x; --t) {
                if (x % t == 0) {
                    return static_cast<int>(x % 1337);
                }
            }
        }

        return 9;
    }
};
