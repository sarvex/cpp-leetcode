#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> d;
    for (int i = 0;; ++i) {
      int x = nums[i];
      int y = target - x;
      if (d.contains(y)) {
        return {d[y], i};
      }
      d[x] = i;
    }
  }
};
