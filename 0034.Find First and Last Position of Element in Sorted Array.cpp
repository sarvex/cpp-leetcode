/**
 * @brief Find first and last position of element in sorted array
 * @intuition Use binary search twice - once for first, once for last
 * @approach Use lower_bound for start and end positions
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto searchRange(const std::vector<int>& nums,
                                        const int target) -> std::vector<int> {
    const auto first =
        std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    const auto last =
        std::lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();

    if (first == last) {
      return {-1, -1};
    }

    return {static_cast<int>(first), static_cast<int>(last - 1)};
  }
};
