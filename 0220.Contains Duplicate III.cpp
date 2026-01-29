/**
 * @brief Sliding window with ordered set for range queries
 * @intuition Maintain sorted window of size indexDiff, query for value range
 * @approach Use set with lower_bound to find values within valueDiff
 * @complexity Time: O(n log k), Space: O(k) where k is indexDiff
 */
#include <set>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto containsNearbyAlmostDuplicate(const std::vector<int>& nums, 
                                                    int indexDiff, int valueDiff) const -> bool {
    std::set<long> window;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      const auto value = static_cast<long>(nums[i]);
      auto it = window.lower_bound(value - valueDiff);
      if (it != window.end() && *it <= value + valueDiff) {
        return true;
      }
      window.insert(value);
      if (i >= indexDiff) {
        window.erase(static_cast<long>(nums[i - indexDiff]));
      }
    }
    return false;
  }
};
