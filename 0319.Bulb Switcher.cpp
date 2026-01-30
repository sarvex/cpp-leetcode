/**
 * @brief Count bulbs that remain on after n rounds
 * @intuition Bulb i is on iff it has odd number of divisors (perfect squares only)
 * @approach Count perfect squares up to n
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int bulbSwitch(int n) {
        return static_cast<int>(sqrt(n));
    }
};
