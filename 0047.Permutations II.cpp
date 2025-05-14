#include <algorithm>
#include <vector>

class Solution final {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::ranges::sort(nums);
    int n = nums.size();
    std::vector<std::vector<int>> ans;
    std::vector<int> t(n);
    std::vector<bool> vis(n);
    auto dfs = [&](this auto &&dfs, int i) {
      if (i == n) {
        ans.emplace_back(t);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
          continue;
        }
        t[i] = nums[j];
        vis[j] = true;
        dfs(i + 1);
        vis[j] = false;
      }
    };
    dfs(0);
    return ans;
  }
};
