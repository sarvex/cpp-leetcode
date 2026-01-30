/**
 * @brief Binary search to find peak in mountain array
 * @intuition Peak is where arr[mid] > arr[mid+1]; search space reduces by half each step
 * @approach Binary search: if mid is on ascending slope, peak is to the right;
 *           otherwise peak is at mid or to the left.
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto peakIndexInMountainArray(
        const std::vector<int>& arr) -> int {
        int left = 1;
        int right = static_cast<int>(arr.size()) - 2;
        
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
