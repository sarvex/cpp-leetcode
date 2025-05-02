#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }
    std::vector<std::string> d = {"abc", "def",  "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> ans = {""};
    for (auto &i : digits) {
      std::string s = d[i - '2'];
      std::vector<std::string> t;
      for (auto &a : ans) {
        for (auto &b : s) {
          t.push_back(a + b);
        }
      }
      ans = std::move(t);
    }
    return ans;
  }
};
