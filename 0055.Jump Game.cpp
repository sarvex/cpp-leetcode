/**
 * @brief Determine if you can reach the last index
 * @intuition Track the furthest reachable index as you iterate through the array
 * @approach Greedy single pass, updating max reachable index at each position
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto canJump(std::vector<int> const& nums) -> bool {
    int maxReach = 0;
    int const n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i) {
      if (i > maxReach) {
        return false;
      }
      maxReach = std::max(maxReach, i + nums[i]);
    }

    return true;
  }
};
