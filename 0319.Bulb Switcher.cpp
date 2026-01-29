/**
 * @brief Count bulbs that remain on after n rounds
 * @intuition Bulb i is on iff it has odd number of divisors (perfect squares only)
 * @approach Count perfect squares up to n
 * @complexity Time: O(1), Space: O(1)
 */
#include <cmath>

class Solution final {
public:
    [[nodiscard]] constexpr int bulbSwitch(int n) const {
        return static_cast<int>(std::sqrt(n));
    }
};
