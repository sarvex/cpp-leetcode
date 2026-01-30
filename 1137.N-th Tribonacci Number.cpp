/**
 * @brief Compute n-th Tribonacci number iteratively
 * @intuition T(n) = T(n-1) + T(n-2) + T(n-3), similar to Fibonacci but with three terms
 * @approach Use three variables to track last three values. Iterate and update each step.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        while (n--) {
            long long d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return static_cast<int>(a);
    }
};
