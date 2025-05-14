#include <functional>
#include <string>
#include <vector>

class Solution final {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::function<void(int, int, std::string)> dfs = [&](int l, int r,
                                                         std::string t) {
      if (l > n || r > n || l < r)
        return;
      if (l == n && r == n) {
        ans.push_back(t);
        return;
      }
      dfs(l + 1, r, t + "(");
      dfs(l, r + 1, t + ")");
    };
    dfs(0, 0, "");
    return ans;
  }
};
