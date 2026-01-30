/**
 * @brief Check if three points are non-collinear
 * @intuition Valid boomerang means points don't lie on same line
 * @approach Use cross product to check collinearity: (y2-y1)(x3-x2) != (y3-y2)(x2-x1)
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr bool isBoomerang(const vector<vector<int>>& points) {
        const int x1 = points[0][0], y1 = points[0][1];
        const int x2 = points[1][0], y2 = points[1][1];
        const int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
};
