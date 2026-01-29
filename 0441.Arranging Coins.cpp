/**
 * @brief Find number of complete staircase rows with n coins
 * @intuition Row k needs k coins, find max k where k(k+1)/2 <= n
 * @approach Binary search for largest k satisfying the constraint
 * @complexity Time: O(log n) Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] auto arrangeCoins(int n) const -> int {
        long long left = 1;
        long long right = n;

        while (left < right) {
            const long long mid = (left + right + 1) >> 1;
            const long long s = (1 + mid) * mid >> 1;

            if (n < s) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        return static_cast<int>(left);
    }
};
