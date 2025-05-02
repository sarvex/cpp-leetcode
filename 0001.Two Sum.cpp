#include <unordered_map>
#include <vector>

/**
 * Hash map single-pass solution for Two Sum
 * @intuition: Use a hash map to track seen values and their indices for O(1)
 * lookup.
 * @approach: Iterate once, for each element check if complement exists in map,
 * else insert.
 * @complexity: O(n) time, O(n) space
 */
class Solution {
public:
  [[nodiscard]] std::vector<int> twoSum(const std::vector<int> &nums,
                                        int target) const {
    std::unordered_map<int, int> seen;
    for (auto [i, x] = std::pair{0, 0}; i < static_cast<int>(nums.size());
         ++i) {
      x = nums[i];
      const int y = target - x;
      if (auto it = seen.find(y); it != seen.end()) {
        return {it->second, i};
      }
      seen[x] = i;
    }
    return {};
  }
};
