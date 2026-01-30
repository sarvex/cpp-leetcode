/**
 * @brief QuickSort implementation for array sorting
 * @intuition Use partition-based divide and conquer
 * @approach Choose middle element as pivot, partition around it, recurse on halves
 * @complexity Time: O(n log n) average, O(n^2) worst, Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> sortArray(vector<int>& nums) {
        auto quickSort = [&](this auto&& quickSort, int l, int r) -> void {
            if (l >= r) {
                return;
            }
            int i = l - 1, j = r + 1;
            const int x = nums[(l + r) >> 1];
            while (i < j) {
                while (nums[++i] < x) {}
                while (nums[--j] > x) {}
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            quickSort(l, j);
            quickSort(j + 1, r);
        };
        quickSort(0, static_cast<int>(nums.size()) - 1);
        return nums;
    }
};
