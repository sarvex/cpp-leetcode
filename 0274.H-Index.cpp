#include <algorithm>
#include <ranges>
#include <vector>

using std::vector;

class Solution {
public:
  /**
   * @brief Compute the H-Index from citation counts using descending sort and
   * linear scan.
   * @intuition: Sort citations descending; the H-Index is the largest h such
   * that at least h papers have >= h citations.
   * @approach: Use std::ranges to sort, then enumerate and check the h-index
   * condition.
   * @complexity: O(n log n) time, O(1) extra space (in-place sort).
   */
  [[nodiscard]] constexpr int hIndex(const vector<int> &citations) const {
    auto sorted = citations | std::views::transform([](int c) { return c; }) |
                  std::ranges::to<vector>();
    std::ranges::sort(sorted | std::views::reverse);
    for (auto [h, cite] : std::views::enumerate(sorted)) {
      if (cite < static_cast<int>(h) + 1)
        return static_cast<int>(h);
    }
    return static_cast<int>(sorted.size());
  }
};
