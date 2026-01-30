/**
 * @brief Find self-dividing numbers in range
 * @intuition Number is self-dividing if divisible by all its digits (no zeros)
 * @approach Check each number: extract digits and verify divisibility
 * @complexity Time: O((right-left) * log10(right)), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> selfDividingNumbers(const int left, const int right) {
        auto isSelfDividing = [](int x) -> bool {
            for (int y = x; y; y /= 10) {
                const int digit = y % 10;
                if (digit == 0 || x % digit != 0) {
                    return false;
                }
            }
            return true;
        };
        
        std::vector<int> result;
        for (int x = left; x <= right; ++x) {
            if (isSelfDividing(x)) {
                result.push_back(x);
            }
        }
        return result;
    }
};
