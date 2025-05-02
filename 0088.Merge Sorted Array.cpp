#include <algorithm>
#include <vector>

class Solution final {
public:
  /**
   * In-place merge of two sorted arrays from the end.
   * @intuition: Fill from the back to avoid overwriting unmerged elements in
   * nums1.
   * @approach: Use three indices to track the merge position and compare from
   * the end.
   * @complexity: O(m + n) time, O(1) extra space.
   */
  void merge(std::vector<int> &nums1, int m, const std::vector<int> &nums2,
             int n) const {
    auto writeIdx = m + n;
    auto i = m;
    auto j = n;
    while (i > 0 && j > 0) {
      nums1[--writeIdx] =
          (nums1[i - 1] > nums2[j - 1]) ? nums1[--i] : nums2[--j];
    }
    std::copy_n(nums2.begin(), j, nums1.begin());
  }
};
