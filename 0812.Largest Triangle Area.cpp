/**
 * @brief Brute force enumeration using cross product for triangle area
 * @intuition Try all triplets and compute area using shoelace formula
 * @approach For each combination of 3 points, calculate triangle area using
 *           cross product formula: Area = |u1*v2 - u2*v1| / 2. Track maximum.
 * @complexity Time: O(n^3), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto largestTriangleArea(
        const std::vector<std::vector<int>>& points) -> double {
        double ans = 0.0;
        
        for (const auto& p1 : points) {
            const int x1 = p1[0], y1 = p1[1];
            for (const auto& p2 : points) {
                const int x2 = p2[0], y2 = p2[1];
                for (const auto& p3 : points) {
                    const int x3 = p3[0], y3 = p3[1];
                    const int u1 = x2 - x1, v1 = y2 - y1;
                    const int u2 = x3 - x1, v2 = y3 - y1;
                    const double t = std::abs(u1 * v2 - u2 * v1) / 2.0;
                    ans = std::max(ans, t);
                }
            }
        }
        return ans;
    }
};
