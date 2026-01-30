/**
 * @brief Check if robot returns to origin after moves
 * @intuition Track x and y coordinates, check if both return to zero
 * @approach Count moves in each direction, verify net displacement is zero
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool judgeCircle(const string& moves) {
        int x = 0, y = 0;
        for (const char c : moves) {
            switch (c) {
                case 'U': ++y; break;
                case 'D': --y; break;
                case 'L': --x; break;
                case 'R': ++x; break;
            }
        }
        return x == 0 && y == 0;
    }
};
