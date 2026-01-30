/**
 * @brief Check if c can be expressed as sum of two squares
 * @intuition Use two pointers: one from 0, one from sqrt(c)
 * @approach Compare a^2 + b^2 with c, adjust pointers accordingly
 * @complexity Time: O(sqrt(c)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool judgeSquareSum(const int c) {
        long long a = 0;
        auto b = static_cast<long long>(sqrt(c));
        
        while (a <= b) {
            const long long s = a * a + b * b;
            if (s == c) {
                return true;
            }
            if (s < c) {
                ++a;
            } else {
                --b;
            }
        }
        return false;
    }
};
