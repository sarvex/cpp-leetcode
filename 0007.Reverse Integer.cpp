#include <limits>

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    for (; x; x /= 10) {
      if (ans < std::numeric_limits<int>::min() / 10 ||
          ans > std::numeric_limits<int>::max() / 10) {
        return 0;
      }
      ans = ans * 10 + x % 10;
    }
    return ans;
  }
};
