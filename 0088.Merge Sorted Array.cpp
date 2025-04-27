#include <vector>
using namespace std;

class Solution {
public:
  /**
   * Merges two sorted integer arrays nums1 and nums2 into a single sorted array
   * in-place.
   *
   * @param nums1 The first sorted array, with enough space at the end to hold
   * all elements of nums2. The first m elements denote the initial valid
   * elements, and the rest are placeholders.
   * @param m     The number of valid elements in nums1.
   * @param nums2 The second sorted array, with n valid elements.
   * @param n     The number of valid elements in nums2.
   *
   * The merged result is stored in nums1.
   */
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};
