/**
 * @brief Check if digit multiset matches any power of 2
 * @intuition Same digits can form same numbers; compare digit counts
 * @approach Convert n to digit frequency array. Compare with digit frequencies
 *           of all powers of 2 up to 10^9.
 * @complexity Time: O(log^2 n), Space: O(1)
 */
class Solution final {
    [[nodiscard]] static auto getDigitCount(int n) -> std::array<int, 10> {
        std::array<int, 10> cnt{};
        while (n > 0) {
            ++cnt[n % 10];
            n /= 10;
        }
        return cnt;
    }

public:
    [[nodiscard]] static auto reorderedPowerOf2(int n) -> bool {
        const auto target = getDigitCount(n);
        
        for (int i = 1; i <= 1'000'000'000; i <<= 1) {
            if (getDigitCount(i) == target) {
                return true;
            }
        }
        return false;
    }
};
