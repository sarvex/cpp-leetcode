#include <vector>

class Solution final {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
    if (l == r) {
      return {-1, -1};
    }
    return {l, r - 1};
  }
};
