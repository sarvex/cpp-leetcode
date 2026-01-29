/**
 * @brief For each interval find minimum start >= its end
 * @intuition Sort intervals by start, binary search for each end value
 * @approach Store original indices, use lower_bound after sorting
 * @complexity Time: O(n log n) Space: O(n)
 */
#include <algorithm>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findRightInterval(std::vector<std::vector<int>>& intervals) const
        -> std::vector<int> {
        const int n = static_cast<int>(intervals.size());
        std::vector<std::pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            arr.emplace_back(intervals[i][0], i);
        }

        std::sort(arr.begin(), arr.end());

        std::vector<int> ans;
        ans.reserve(n);

        for (const auto& e : intervals) {
            auto j = std::lower_bound(arr.begin(), arr.end(), std::make_pair(e[1], -1)) - arr.begin();
            ans.push_back(j == n ? -1 : arr[j].second);
        }

        return ans;
    }
};
