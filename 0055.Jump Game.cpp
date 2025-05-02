#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution final {
public:
  /**
   * Greedy reachability check for Jump Game
   * @intuition: Track the furthest reachable index as you iterate.
   * @approach: Use a single pass, updating max reachable index; fail if stuck.
   * @complexity: O(n) time, O(1) space

   * @param nums Jump lengths from each index.
   * @return true if last index is reachable, false otherwise.
   */
  [[nodiscard]] static constexpr bool
  canJump(const vector<int> &nums) noexcept {
    int maxReach = 0;
    for (int i = 0, n = static_cast<int>(nums.size()); i < n; ++i) {
      if (i > maxReach)
        return false;
      maxReach = std::max(maxReach, i + nums[i]);
    }
    return true;
  }
};
