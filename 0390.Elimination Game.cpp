/**
 * @brief Find last remaining number after alternating left/right elimination
 * @intuition Track first and last elements, step size doubles each round
 * @approach Update endpoints based on direction and count parity
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto lastRemaining(int n) -> int {
        int a1 = 1;
        int an = n;
        int step = 1;

        for (int i = 0, cnt = n; cnt > 1; cnt >>= 1, step <<= 1, ++i) {
            if (i % 2 == 1) {
                an -= step;
                if (cnt % 2 == 1) {
                    a1 += step;
                }
            } else {
                a1 += step;
                if (cnt % 2 == 1) {
                    an -= step;
                }
            }
        }

        return a1;
    }
};
