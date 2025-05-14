#include <functional>
#include <string>
#include <vector>

class Solution final {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<int> col(n);
    std::vector<int> dg(n << 1);
    std::vector<int> udg(n << 1);
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> t(n, std::string(n, '.'));
    std::function<void(int)> dfs = [&](int i) -> void {
      if (i == n) {
        ans.push_back(t);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
          t[i][j] = 'Q';
          col[j] = dg[i + j] = udg[n - i + j] = 1;
          dfs(i + 1);
          col[j] = dg[i + j] = udg[n - i + j] = 0;
          t[i][j] = '.';
        }
      }
    };
    dfs(0);
    return ans;
  }
};
