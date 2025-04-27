#include <vector>
using namespace std;

class Solution {
public:
  /**
   * Removes duplicates from a sorted array in-place such that each unique
   * element appears at most twice.
   *
   * @param nums Reference to a vector of integers sorted in non-decreasing
   * order.
   * @return The new length of the array after removing extra duplicates (at
   * most two occurrences allowed).
   *
   * The function modifies the input vector in-place to retain at most two
   * occurrences of each element and returns the new length. Elements beyond the
   * returned length are unspecified.
   */
  int removeDuplicates(vector<int> &nums) {
    int insertPos = 0; // Position to insert the next allowed element
    for (int number : nums) {
      // Allow the first two elements or if the current number is not the same
      // as the element two positions before
      if (insertPos < 2 || number != nums[insertPos - 2]) {
        nums[insertPos] = number;
        ++insertPos;
      }
    }
    return insertPos;
  }
};
