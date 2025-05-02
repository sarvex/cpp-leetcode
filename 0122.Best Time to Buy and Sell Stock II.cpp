#include <numeric>
#include <ranges>
#include <vector>

using namespace std;
using namespace std::ranges;

class Solution {
public:
  /**
   * Greedy summing of positive price differences for max profit.
   * @intuition: Buy on every upward trend; sum all gains.
   * @approach: Use std::ranges::adjacent_transform and std::ranges::fold_left
   * for clarity and conciseness.
   * @complexity: O(n) time, O(1) space.
   */
  int maxProfit(const vector<int> &prices) const {
    // Compute sum of all positive differences between consecutive days
    auto diffs = prices | views::slide(2) | views::transform([](const auto &w) {
                   return std::max(0, w[1] - w[0]);
                 });
    return std::accumulate(diffs.begin(), diffs.end(), 0);
  }
};
