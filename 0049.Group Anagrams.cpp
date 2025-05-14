#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution final {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> d;
    for (auto &s : strs) {
      std::string k = s;
      std::sort(k.begin(), k.end());
      d[k].emplace_back(s);
    }
    std::vector<std::vector<std::string>> ans;
    for (auto &[_, v] : d)
      ans.emplace_back(v);
    return ans;
  }
};
