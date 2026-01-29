/**
 * @brief Two-pointer in-place array deduplication
 * @intuition Since array is sorted, duplicates are adjacent
 * @approach Use write pointer that only advances when finding unique elements
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto removeDuplicates(std::vector<int>& nums) noexcept
      -> int {
    if (nums.empty()) {
      return 0;
    }

    int writePos = 0;
    for (size_t readPos = 1; readPos < nums.size(); ++readPos) {
      if (nums[readPos] != nums[writePos]) {
        ++writePos;
        nums[writePos] = nums[readPos];
      }
    }

    return writePos + 1;
  }
};
