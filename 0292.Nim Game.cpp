/**
 * @brief Nim game winning strategy
 * @intuition If n % 4 == 0, opponent can always mirror your moves
 * @approach Mathematical: you win iff n is not divisible by 4
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
