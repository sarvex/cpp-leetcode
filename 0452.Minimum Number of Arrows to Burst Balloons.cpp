/**
 * @brief Find minimum arrows to burst all balloons
 * @intuition Greedy: sort by end, shoot at end of current balloon
 * @approach Arrow at position x bursts all balloons covering x
 * @complexity Time: O(n log n) Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findMinArrowShots(std::vector<std::vector<int>>& points) const -> int {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        long long last = -(1LL << 60);

        for (const auto& p : points) {
            const int a = p[0];
            const int b = p[1];
            if (a > last) {
                ++ans;
                last = b;
            }
        }

        return ans;
    }
};
