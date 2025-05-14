#include <algorithm>
#include <functional>
#include <vector>

class Solution final {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> t;
    std::function<void(int, int)> dfs = [&](int i, int s) {
      if (s == 0) {
        ans.emplace_back(t);
        return;
      }
      if (i >= candidates.size() || s < candidates[i]) {
        return;
      }
      for (int j = i; j < candidates.size(); ++j) {
        if (j > i && candidates[j] == candidates[j - 1]) {
          continue;
        }
        t.emplace_back(candidates[j]);
        dfs(j + 1, s - candidates[j]);
        t.pop_back();
      }
    };
    dfs(0, target);
    return ans;
  }
};
