#include <string>
#include <vector>

class Solution {
public:
  std::string intToRoman(int num) {
    std::vector<std::string> cs = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                   "XL", "X",  "IX", "V",  "IV", "I"};
    std::vector<int> vs = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
    std::string ans;
    for (int i = 0; i < cs.size(); ++i) {
      while (num >= vs[i]) {
        num -= vs[i];
        ans += cs[i];
      }
    }
    return ans;
  }
};
