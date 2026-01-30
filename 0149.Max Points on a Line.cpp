/**
 * @brief Find max points on a line using collinearity check
 * @intuition Three points are collinear if cross product of vectors is zero
 * @approach For each pair, count collinear points using cross product
 * @complexity Time: O(n^3), Space: O(1)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto maxPoints(vector<vector<int>>& points) -> int {
        const int n = static_cast<int>(points.size());
        int maxCount = 1;

        for (int i = 0; i < n; ++i) {
            const int x1 = points[i][0];
            const int y1 = points[i][1];

            for (int j = i + 1; j < n; ++j) {
                const int x2 = points[j][0];
                const int y2 = points[j][1];
                int count = 2;

                for (int k = j + 1; k < n; ++k) {
                    const int x3 = points[k][0];
                    const int y3 = points[k][1];

                    // Check collinearity: (y2-y1)*(x3-x1) == (y3-y1)*(x2-x1)
                    const long long cross1 = static_cast<long long>(y2 - y1) * (x3 - x1);
                    const long long cross2 = static_cast<long long>(y3 - y1) * (x2 - x1);

                    if (cross1 == cross2) {
                        ++count;
                    }
                }

                maxCount = std::max(maxCount, count);
            }
        }

        return maxCount;
    }
};
