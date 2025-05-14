#include <vector>

class Solution final {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<std::vector<int>> ans;
    std::vector<int> t(n);
    std::vector<bool> vis(n);
    auto dfs = [&](this auto &&dfs, int i) -> void {
      if (i == n) {
        ans.emplace_back(t);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (!vis[j]) {
          vis[j] = true;
          t[i] = nums[j];
          dfs(i + 1);
          vis[j] = false;
        }
      }
    };
    dfs(0);
    return ans;
  }
};
