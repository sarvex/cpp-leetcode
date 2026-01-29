/**
 * @brief Check if polygon formed by points is convex
 * @intuition Convex polygon has all cross products same sign
 * @approach Check cross product sign for each triple of consecutive points
 * @complexity Time: O(n) Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto isConvex(const std::vector<std::vector<int>>& points) const -> bool {
        const int n = static_cast<int>(points.size());
        long long pre = 0;

        for (int i = 0; i < n; ++i) {
            const int x1 = points[(i + 1) % n][0] - points[i][0];
            const int y1 = points[(i + 1) % n][1] - points[i][1];
            const int x2 = points[(i + 2) % n][0] - points[i][0];
            const int y2 = points[(i + 2) % n][1] - points[i][1];

            const long long cur = 1LL * x1 * y2 - 1LL * x2 * y1;

            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }

        return true;
    }
};
