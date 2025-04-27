#include <vector>
using std::vector;

class Solution {
public:
  /**
   * Removes all instances of 'val' from the input vector 'nums' in-place.
   *
   * @param nums Reference to a vector of integers. Modified in-place such that
   *             the first k elements are those not equal to 'val'.
   * @param val  The integer value to remove from the vector.
   * @return     The number of elements remaining after removal (new length).
   *
   * Approach:
   *   Uses the two-pointer technique. Iterates through the vector, and whenever
   *   an element not equal to 'val' is found, it is written to the next
   * position at index 'k'. After processing, the first 'k' elements are those
   * not equal to 'val'.
   */
  int removeElement(vector<int> &nums, int val) {
    int k = 0;
    const int size = nums.size();
    for (int i = 0; i < size; ++i) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        ++k;
      }
    }
    // After loop, first 'k' elements are those not equal to val
    return k;
  }
};
