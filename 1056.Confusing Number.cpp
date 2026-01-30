/**
 * @brief Check if number rotated 180 degrees gives different valid number
 * @intuition Only 0,1,6,8,9 are valid rotated digits; check if result differs
 * @approach Build rotated number using digit mapping, compare with original
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool confusingNumber(int n) {
        constexpr int d[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = n, y = 0;
        while (x) {
            const int v = x % 10;
            if (d[v] < 0) {
                return false;
            }
            y = y * 10 + d[v];
            x /= 10;
        }
        return y != n;
    }
};
