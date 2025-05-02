#include <algorithm>
#include <ranges>
#include <vector>

class Solution {
public:
  /**
   * @brief Two-pass greedy solution for distributing candies.
   * @intuition Each child must get more candies than neighbors if their rating
   * is higher; two sweeps (left-to-right, right-to-left) ensure both
   * constraints.
   * @approach Use two arrays to track increasing sequences from both
   * directions, then sum the max at each position.
   * @complexity Time: O(n), Space: O(n)
   */
  int candy(const std::vector<int> &ratings) const {
    const auto n = std::ssize(ratings);
    if (n == 0)
      return 0;
    std::vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; ++i)
      if (ratings[i] > ratings[i - 1])
        left[i] = left[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
      if (ratings[i] > ratings[i + 1])
        right[i] = right[i + 1] + 1;
    return std::ranges::fold_left(
        std::views::iota(0, n), 0,
        [&](int acc, int i) { return acc + std::max(left[i], right[i]); });
  }
};
