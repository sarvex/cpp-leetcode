#include <string>

class Solution final {
public:
  std::string countAndSay(int n) {
    std::string s = "1";
    while (--n) {
      std::string t = "";
      for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() && s[j] == s[i])
          ++j;
        t += std::to_string(j - i);
        t += s[i];
        i = j;
      }
      s = t;
    }
    return s;
  }
};
