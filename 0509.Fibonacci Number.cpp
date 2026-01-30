/**
 * @brief Compute nth Fibonacci number iteratively
 * @intuition F(n) = F(n-1) + F(n-2); use two variables to track previous values
 * @approach Iterate n times, updating two variables that hold consecutive Fibonacci numbers.
 *           After n iterations, the first variable holds F(n).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr auto fib(int n) -> int {
        int a = 0, b = 1;
        while (n--) {
            const int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};
