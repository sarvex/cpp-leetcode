#include <string>
#include <vector>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int n = s.size();
    std::vector<std::vector<bool>> f(n, std::vector<bool>(n, true));
    int k = 0, mx = 1;
    for (int i = n - 2; ~i; --i) {
      for (int j = i + 1; j < n; ++j) {
        f[i][j] = false;
        if (s[i] == s[j]) {
          f[i][j] = f[i + 1][j - 1];
          if (f[i][j] && mx < j - i + 1) {
            mx = j - i + 1;
            k = i;
          }
        }
      }
    }
    return s.substr(k, mx);
  }
};
