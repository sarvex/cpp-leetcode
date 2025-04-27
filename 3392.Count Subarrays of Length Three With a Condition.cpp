#include <vector>
using std::vector;

class Solution {
public:
  /**
   * Counts the number of subarrays of length 3 where the middle element is
   * exactly half the sum of its neighbors.
   *
   * @param nums A vector of integers representing the input array.
   * @return The count of subarrays of length 3 that satisfy the condition.
   */
  int countSubarrays(const vector<int> &nums) {
    int count = 0;
    const int size = nums.size() - 1;
    // Iterate over all possible subarrays of length 3
    for (size_t i = 1; i + 1 < size; ++i) {
      // Check if the middle element is half the sum of its neighbors
      if (nums[i] == 2 * (nums[i - 1] + nums[i + 1])) {
        ++count;
      }
    }
    return count;
  }
};
