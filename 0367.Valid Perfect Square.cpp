/**
 * @brief Check if number is a perfect square using binary search
 * @intuition Binary search for integer square root
 * @approach Find smallest x where x*x >= num, check if x*x == num
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isPerfectSquare(const int num) {
        int l = 1;
        int r = num;
        
        while (l < r) {
            const int mid = l + (r - l) / 2;
            if (1LL * mid * mid >= num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return 1LL * l * l == num;
    }
};
