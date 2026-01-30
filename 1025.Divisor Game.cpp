/**
 * @brief Mathematical game theory analysis
 * @intuition Even numbers win (can always reduce by 1), odd numbers lose
 * @approach Simply check if n is even
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr bool divisorGame(const int n) {
        return n % 2 == 0;
    }
};
