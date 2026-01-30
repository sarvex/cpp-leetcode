/**
 * @brief Binary search for fixed point (arr[i] == i)
 * @intuition Array is sorted and distinct; binary search for equality
 * @approach If arr[mid] >= mid, search left; else search right
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int fixedPoint(const vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (arr[mid] >= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left] == left ? left : -1;
    }
};
