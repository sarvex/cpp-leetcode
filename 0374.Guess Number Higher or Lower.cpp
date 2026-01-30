/**
 * @brief Find the picked number using binary search with guess API
 * @intuition Binary search narrows down the target in logarithmic time
 * @approach Adjust search range based on guess() return value
 * @complexity Time: O(log n), Space: O(1)
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *                0 if num is equal to the picked number
 * int guess(int num);
 */

class Solution final {
public:
    [[nodiscard]] static auto guessNumber(int n) -> int {
        int left = 1;
        int right = n;

        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
