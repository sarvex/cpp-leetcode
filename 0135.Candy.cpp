/**
 * @brief Two-pass greedy solution for distributing candies
 * @intuition Each child must get more candies than neighbors if their rating is higher
 * @approach Use two arrays to track increasing sequences from both directions, then sum the max at each position
 * @complexity Time: O(n), Space: O(n)
 */

#include <algorithm>
#include <ranges>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto candy(const vector<int>& ratings) -> int {
        const auto n = std::ssize(ratings);
        if (n == 0) {
            return 0;
        }

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        return std::ranges::fold_left(
            std::views::iota(0, n), 0,
            [&](int acc, int i) { return acc + std::max(left[i], right[i]); });
    }
};
