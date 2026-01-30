/**
 * @brief Quickselect algorithm for kth largest element
 * @intuition Partial sorting via partitioning finds kth element in O(n) average
 * @approach Recursively partition array around pivot until kth position found
 * @complexity Time: O(n) average, O(n^2) worst, Space: O(log n) for recursion
 */

class Solution final {
public:
    [[nodiscard]] static auto findKthLargest(std::vector<int>& nums, int k) -> int {
        const auto n = static_cast<int>(nums.size());
        const int targetIndex = n - k;
        
        auto quickSelect = [&](this auto&& quickSelect, int left, int right) -> int {
            if (left == right) {
                return nums[left];
            }
            int i = left - 1;
            int j = right + 1;
            const int pivot = nums[(left + right) / 2];
            
            while (i < j) {
                while (nums[++i] < pivot) {}
                while (nums[--j] > pivot) {}
                if (i < j) {
                    std::swap(nums[i], nums[j]);
                }
            }
            
            if (j < targetIndex) {
                return quickSelect(j + 1, right);
            }
            return quickSelect(left, j);
        };
        
        return quickSelect(0, n - 1);
    }
};
