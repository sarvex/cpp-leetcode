/**
 * @brief Check if points have line of reflection parallel to y-axis
 * @intuition Reflection line must be at x = (minX + maxX) / 2
 * @approach Find min/max x, check each point has reflection partner
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool isReflected(const std::vector<std::vector<int>>& points) {
        constexpr int inf = 1 << 30;
        int minX = inf;
        int maxX = -inf;
        std::set<std::pair<int, int>> pointSet;
        
        for (const auto& p : points) {
            minX = std::min(minX, p[0]);
            maxX = std::max(maxX, p[0]);
            pointSet.emplace(p[0], p[1]);
        }
        
        const int sum = minX + maxX;
        for (const auto& p : points) {
            if (!pointSet.contains({sum - p[0], p[1]})) {
                return false;
            }
        }
        return true;
    }
};
