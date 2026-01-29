/**
 * @brief Wiggle sort array so nums[0] < nums[1] > nums[2] < nums[3]...
 * @intuition Place smaller half at even indices, larger half at odd indices
 * @approach Sort then interleave from middle to avoid equal adjacent elements
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    void wiggleSort(std::vector<int>& nums) const {
        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        
        const int n = static_cast<int>(nums.size());
        int i = (n - 1) >> 1;
        int j = n - 1;
        
        for (int k = 0; k < n; ++k) {
            if (k % 2 == 0) {
                nums[k] = sorted[i--];
            } else {
                nums[k] = sorted[j--];
            }
        }
    }
};
