/**
 * @brief Find minimum operations to reduce n to 1 (n/2 if even, +/-1 if odd)
 * @intuition For odd n, prefer +1 if it creates trailing zeros (except n=3)
 * @approach Greedy: divide by 2 when even, adjust odd numbers to maximize trailing zeros
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto integerReplacement(int n) -> int {
        int ans = 0;
        long num = n;

        while (num != 1) {
            if ((num & 1) == 0) {
                num >>= 1;
            } else if (num != 3 && (num & 3) == 3) {
                ++num;
            } else {
                --num;
            }
            ++ans;
        }

        return ans;
    }
};
