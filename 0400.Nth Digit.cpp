/**
 * @brief Find nth digit in concatenated integers 123456789101112...
 * @intuition Count how many digits are used by numbers of each length (1-digit, 2-digit, etc.)
 * @approach Skip digit ranges until finding the range containing n, then locate exact digit
 * @complexity Time: O(log n) Space: O(1)
 */
#include <cmath>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto findNthDigit(int n) const -> int {
        int k = 1;
        int cnt = 9;

        while (1LL * k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }

        const int num = static_cast<int>(std::pow(10, k - 1)) + (n - 1) / k;
        const int idx = (n - 1) % k;

        return std::to_string(num)[idx] - '0';
    }
};
