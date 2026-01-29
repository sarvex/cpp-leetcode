/**
 * @brief Single-pass hash map lookup for Two Sum problem
 * @intuition Use a hash map to track seen values and their indices
 * @approach Iterate once, storing each value's index; check if complement exists
 * @complexity Time: O(n), Space: O(n)
 */

#include <unordered_map>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto twoSum(const std::vector<int>& nums,
                                   const int target) -> std::vector<int> {
    std::unordered_map<int, int> seen;
    for (auto i = 0uz; i < nums.size(); ++i) {
      const auto complement = target - nums[i];
      if (const auto it = seen.find(complement); it != seen.end()) {
        return {static_cast<int>(it->second), static_cast<int>(i)};
      }
      seen[nums[i]] = static_cast<int>(i);
    }
    return {};
  }
};
