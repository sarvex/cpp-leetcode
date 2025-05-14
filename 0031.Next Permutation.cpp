#include <algorithm>
#include <vector>

class Solution final {
public:
  void nextPermutation(std::vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    while (~i && nums[i] >= nums[i + 1]) {
      --i;

      if (~i) {
        for (int j = n - 1; j > i; --j) {
          if (nums[j] > nums[i]) {
            std::swap(nums[i], nums[j]);
            break;
          }
        }
      }
      reverse(nums.begin() + i + 1, nums.end());
    }
  }
};
