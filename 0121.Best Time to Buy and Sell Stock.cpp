#include <algorithm>
#include <ranges>
#include <vector>

using std::ranges;
using std::vector;

class Solution {
public:
  /**
   * Single-pass min tracking for max profit in stock prices.
   * @intuition: Track the minimum price so far and compute the max profit at
   * each step.
   * @approach: Iterate through prices, updating the minimum and calculating
   * profit on the fly.
   * @complexity: Time O(n), Space O(1)
   * @param prices List of daily stock prices.
   * @return Maximum achievable profit.
   */
  int maxProfit(const vector<int> &prices) const {
    if (prices.empty())
      return 0;
    int minPrice = prices.front();
    int maxProfit = 0;
    for (const auto price : prices) {
      maxProfit = ranges::max(maxProfit, price - minPrice);
      minPrice = ranges::min(minPrice, price);
    }
    return maxProfit;
  }
};
