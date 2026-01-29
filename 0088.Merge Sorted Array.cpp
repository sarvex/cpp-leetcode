/**
 * @brief In-place merge of two sorted arrays from the end
 * @intuition Fill from the back to avoid overwriting unmerged elements in nums1
 * @approach Use three indices tracking merge position; compare from end of both arrays
 * @complexity Time: O(m + n), Space: O(1)
 */
class Solution final {
public:
    static auto merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) -> void {
        auto write = m + n;
        
        while (m > 0 && n > 0) {
            nums1[--write] = (nums1[m - 1] > nums2[n - 1]) ? nums1[--m] : nums2[--n];
        }
        
        ranges::copy_n(nums2.begin(), n, nums1.begin());
    }
};
