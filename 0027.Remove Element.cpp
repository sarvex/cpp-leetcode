/**
 * @brief In-place removal using STL algorithms
 * @intuition Use standard algorithms to minimize manual iteration
 * @approach Use std::remove to shift unwanted elements, return new size
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto removeElement(std::vector<int>& nums,
                                          const int val) -> int {
    const auto newEnd = std::remove(nums.begin(), nums.end(), val);
    return static_cast<int>(std::distance(nums.begin(), newEnd));
  }
};
