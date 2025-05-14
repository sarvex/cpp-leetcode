#include <algorithm>
#include <vector>

class Solution final {
  /**
   * @brief In-place removal using STL algorithms.
   * @intuition Use standard algorithms to minimize manual iteration.
   * @approach Use std::remove to shift unwanted elements, then return new size.
   * @complexity Time: O(n)
   * @complexity Space: O(1)
   */
public:
  int removeElement(std::vector<int> &nums, int val) {
    const auto newEnd = std::remove(nums.begin(), nums.end(), val);
    return static_cast<int>(std::distance(nums.begin(), newEnd));
  }
};
