#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    int n = strs.size();
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 1; j < n; ++j) {
        if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};
