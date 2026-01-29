/**
 * @brief Find minimum intervals to remove for non-overlapping set
 * @intuition Greedy: keep intervals ending earliest to maximize room
 * @approach Sort by end time, count intervals that fit without overlap
 * @complexity Time: O(n log n) Space: O(1)
 */
#include <algorithm>
#include <climits>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) const -> int {
        std::ranges::sort(intervals, [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int ans = static_cast<int>(intervals.size());
        int pre = INT_MIN;

        for (const auto& e : intervals) {
            const int l = e[0];
            const int r = e[1];
            if (pre <= l) {
                --ans;
                pre = r;
            }
        }

        return ans;
    }
};
