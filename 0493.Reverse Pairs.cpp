/**
 * @brief Count reverse pairs where nums[i] > 2 * nums[j] and i < j
 * @intuition Modified merge sort: count cross-inversions during merge
 * @approach During merge, count pairs before merging sorted halves
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <functional>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto reversePairs(std::vector<int>& nums) const -> int {
        const int n = static_cast<int>(nums.size());
        std::vector<int> temp(n);

        std::function<int(int, int)> mergeSort = [&](int left, int right) -> int {
            if (left >= right) {
                return 0;
            }

            const int mid = left + (right - left) / 2;
            int count = mergeSort(left, mid) + mergeSort(mid + 1, right);

            int i = left;
            int j = mid + 1;
            while (i <= mid && j <= right) {
                if (nums[i] <= 2LL * nums[j]) {
                    ++i;
                } else {
                    count += mid - i + 1;
                    ++j;
                }
            }

            i = left;
            j = mid + 1;
            int k = 0;
            while (i <= mid && j <= right) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                } else {
                    temp[k++] = nums[j++];
                }
            }
            while (i <= mid) {
                temp[k++] = nums[i++];
            }
            while (j <= right) {
                temp[k++] = nums[j++];
            }
            for (int idx = left; idx <= right; ++idx) {
                nums[idx] = temp[idx - left];
            }

            return count;
        };

        return mergeSort(0, n - 1);
    }
};
