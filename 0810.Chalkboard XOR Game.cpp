/**
 * @brief Game theory analysis for chalkboard XOR game
 * @intuition Alice wins if XOR is already 0 or she has even-count advantage
 * @approach If total XOR is 0, current player wins. If array size is even,
 *           first player (Alice) always has a winning strategy as she can
 *           always find a move that doesn't make XOR zero for opponent.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto xorGame(const std::vector<int>& nums) -> bool {
        if (nums.size() % 2 == 0) return true;
        
        int x = 0;
        for (const int v : nums) {
            x ^= v;
        }
        return x == 0;
    }
};
