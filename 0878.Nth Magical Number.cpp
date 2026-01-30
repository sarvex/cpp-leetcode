/**
 * @brief Binary search for nth number divisible by a or b
 * @intuition Count of magical numbers <= x is x/a + x/b - x/lcm(a,b)
 * @approach Binary search on answer. For each candidate x, count how many magical
 *           numbers are <= x using inclusion-exclusion principle.
 * @complexity Time: O(log(n * max(a,b))), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto nthMagicalNumber(int n, int a, int b) -> int {
        constexpr int mod = 1'000'000'007;
        const long long c = std::lcm(static_cast<long long>(a), static_cast<long long>(b));
        
        long long l = 0, r = static_cast<long long>(a + b) * n;
        while (l < r) {
            const long long mid = (l + r) >> 1;
            if (mid / a + mid / b - mid / c >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return static_cast<int>(l % mod);
    }
};
