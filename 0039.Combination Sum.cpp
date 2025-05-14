#include <algorithm>
#include <functional>
#include <vector>

class Solution final {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> t;
    std::function<void(int, int)> dfs = [&](int i, int s) {
      if (s == 0) {
        ans.emplace_back(t);
        return;
      }
      if (s < candidates[i]) {
        return;
      }
      for (int j = i; j < candidates.size(); ++j) {
        t.push_back(candidates[j]);
        dfs(j, s - candidates[j]);
        t.pop_back();
      }
    };
    dfs(0, target);
    return ans;
  }
};
