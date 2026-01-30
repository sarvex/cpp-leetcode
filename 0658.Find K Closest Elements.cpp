/**
 * @brief Find k closest elements to x in sorted array
 * @intuition Use binary search to find optimal starting position of window
 * @approach Binary search for left bound where window [l, l+k] is optimal
 * @complexity Time: O(log(n-k) + k), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findClosestElements(const vector<int>& arr, const int k, const int x) {
        int l = 0;
        int r = arr.size() - k;
        
        while (l < r) {
            const int mid = (l + r) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
