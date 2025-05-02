#include <algorithm>
#include <vector>

class Solution {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ans = 1 << 30;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        int t = nums[i] + nums[j] + nums[k];
        if (t == target)
          return t;
        if (std::abs(t - target) < std::abs(ans - target))
          ans = t;
        if (t > target)
          --k;
        else
          ++j;
      }
    }
    return ans;
  }
};
