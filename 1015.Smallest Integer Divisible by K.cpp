/**
 * @brief Cycle detection for repunit divisibility
 * @intuition Build repunits modulo k; if cycle found before divisible, return -1
 * @approach Iterate building number mod k, detect cycle within k iterations
 * @complexity Time: O(k), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr int smallestRepunitDivByK(const int k) {
        int n = 1 % k;
        for (int i = 1; i <= k; ++i) {
            if (n == 0) {
                return i;
            }
            n = (n * 10 + 1) % k;
        }
        return -1;
    }
};
