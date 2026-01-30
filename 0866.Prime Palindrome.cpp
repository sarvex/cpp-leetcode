/**
 * @brief Linear search for smallest prime palindrome >= n
 * @intuition Check each candidate for palindrome and prime properties
 * @approach Iterate from n, checking if number is palindrome and prime.
 *           Skip 8-digit palindromes (all divisible by 11) for optimization.
 * @complexity Time: O(n * sqrt(n)), Space: O(log n)
 */
class Solution final {
    [[nodiscard]] static auto isPrime(int x) -> bool {
        if (x < 2) return false;
        for (int v = 2; v * v <= x; ++v) {
            if (x % v == 0) return false;
        }
        return true;
    }

    [[nodiscard]] static auto reverse(int x) -> int {
        int res = 0;
        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }

public:
    [[nodiscard]] static auto primePalindrome(int n) -> int {
        while (true) {
            if (reverse(n) == n && isPrime(n)) return n;
            if (n > 10'000'000 && n < 100'000'000) {
                n = 100'000'000;
            }
            ++n;
        }
    }
};
