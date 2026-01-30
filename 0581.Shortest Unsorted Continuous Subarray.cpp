/**
 * @brief Find shortest subarray to sort for whole array to be sorted
 * @intuition Compare with sorted version; find leftmost and rightmost mismatches
 * @approach Sort copy, find first and last positions where arrays differ
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int left = 0;
        int right = static_cast<int>(sorted.size()) - 1;
        
        while (left <= right && sorted[left] == nums[left]) {
            ++left;
        }
        while (left <= right && sorted[right] == nums[right]) {
            --right;
        }
        
        return right - left + 1;
    }
};
