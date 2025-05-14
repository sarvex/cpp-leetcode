#include <string>
#include <vector>

class Solution final {
private:
  std::vector<int> Next(std::string str) {
    std::vector<int> n(str.length());
    n[0] = -1;
    int i = 0, pre = -1;
    int len = str.length();
    while (i < len) {
      while (pre >= 0 && str[i] != str[pre])
        pre = n[pre];
      ++i, ++pre;
      if (i >= len)
        break;
      if (str[i] == str[pre])
        n[i] = n[pre];
      else
        n[i] = pre;
    }
    return n;
  }

public:
  int strStr(std::string haystack, std::string needle) {
    if (0 == needle.length())
      return 0;

    std::vector<int> n(Next(needle));

    int len = haystack.length() - needle.length() + 1;
    for (int i = 0; i < len; ++i) {
      int j = 0, k = i;
      while (j < needle.length() && k < haystack.length()) {
        if (haystack[k] != needle[j]) {
          if (n[j] >= 0) {
            j = n[j];
            continue;
          } else
            break;
        }
        ++k, ++j;
      }
      if (j >= needle.length())
        return k - j;
    }

    return -1;
  }
};
