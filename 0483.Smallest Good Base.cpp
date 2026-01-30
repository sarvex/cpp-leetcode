/**
 * @brief Find smallest base k such that n = 1 + k + k^2 + ... + k^m
 * @intuition For m digits in base k: n = (k^(m+1) - 1) / (k - 1)
 * @approach Try decreasing m values, binary search or compute k directly
 * @complexity Time: O(log^2 n), Space: O(1)
 */
#include <cmath>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto smallestGoodBase(const std::string& n) const -> std::string {
        const long long v = std::stoll(n);
        const int mx = static_cast<int>(std::floor(std::log(v) / std::log(2)));

        for (int m = mx; m > 1; --m) {
            const int k = static_cast<int>(std::pow(v, 1.0 / m));
            long long mul = 1;
            long long sum = 1;

            for (int i = 0; i < m; ++i) {
                mul *= k;
                sum += mul;
            }

            if (sum == v) {
                return std::to_string(k);
            }
        }

        return std::to_string(v - 1);
    }
};
