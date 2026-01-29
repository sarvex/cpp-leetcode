/**
 * @brief DP for painting houses with k colors
 * @intuition Each house uses minimum cost from different color of previous house
 * @approach Track DP state, find minimum excluding current color
 * @complexity Time: O(n * k^2), Space: O(k)
 */
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto minCostII(const std::vector<std::vector<int>>& costs) const -> int {
    const auto n = costs.size();
    const auto k = costs[0].size();
    
    std::vector<int> dp = costs[0];
    
    for (std::size_t i = 1; i < n; ++i) {
      std::vector<int> newDp = costs[i];
      for (std::size_t j = 0; j < k; ++j) {
        int minPrev = INT_MAX;
        for (std::size_t h = 0; h < k; ++h) {
          if (h != j) {
            minPrev = std::min(minPrev, dp[h]);
          }
        }
        newDp[j] += minPrev;
      }
      dp = std::move(newDp);
    }
    return *std::min_element(dp.begin(), dp.end());
  }
};
