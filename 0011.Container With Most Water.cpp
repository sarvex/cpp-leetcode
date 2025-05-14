#include <vector>

class Solution final {
public:
  int maxArea(std::vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      int t = std::min(height[l], height[r]) * (r - l);
      ans = std::max(ans, t);
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return ans;
  }
};
