#include <limits>
class Solution final {
public:
  int divide(int a, int b) {
    if (b == 1) {
      return a;
    }
    if (a == std::numeric_limits<int>::min && b == -1) {
      return std::numeric_limits<int>::max();
    }
    bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
    a = a > 0 ? -a : a;
    b = b > 0 ? -b : b;
    int ans = 0;
    while (a <= b) {
      int x = b;
      int cnt = 1;
      while (x >= (std::numeric_limits<int>::min() >> 1) && a <= (x << 1)) {
        x <<= 1;
        cnt <<= 1;
      }
      ans += cnt;
      a -= x;
    }
    return sign ? ans : -ans;
  }
};
