#include <algorithm>
#include <vector>

class Solution final {
public:
  /**
   * Greedy minimum-jump solver for Jump Game II.
   * @intuition Use the farthest point reachable in the current jump range; jump
   * only when needed.
   * @approach Greedily extend the reachable range, increment jump count when
   * end of current range is reached.
   * @complexity Time: O(n), Space: O(1)
   */
  [[nodiscard]] int jump(const std::vector<int> &nums) const {
    int jumpCount = 0;
    int currentJumpLimit = 0;
    int maxReachableIndex = 0;
    for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
      maxReachableIndex = std::max(maxReachableIndex, i + nums[i]);
      if (i == currentJumpLimit) {
        ++jumpCount;
        currentJumpLimit = maxReachableIndex;
      }
    }
    return jumpCount;
  }
};
