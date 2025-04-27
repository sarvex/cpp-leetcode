#include <algorithm>
#include <vector>

using std::reverse;
using std::vector;

class Solution {
public:
  /**
   * Rotates the array to the right by k steps.
   *
   * @approach This operation is performed in-place using the reversal
   * algorithm.
   *
   * @param nums Reference to the vector of integers to be rotated.
   * @param k Number of steps to rotate the array to the right.
   */
  void rotate(vector<int> &nums, int k) {
    const int n = nums.size();
    if (n == 0 || k % n == 0)
      return;  // No rotation needed
    k = k % n; // Ensure k is within bounds
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
