/**
 * @brief Count boomerangs (i,j,k) where dist(i,j) = dist(i,k)
 * @intuition For each point, count pairs at same distance
 * @approach For each anchor, group points by squared distance, count permutations
 * @complexity Time: O(n^2) Space: O(n)
 */
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto numberOfBoomerangs(const std::vector<std::vector<int>>& points) const -> int {
        int ans = 0;

        for (const auto& p1 : points) {
            std::unordered_map<int, int> cnt;
            for (const auto& p2 : points) {
                const int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                ans += cnt[d];
                ++cnt[d];
            }
        }

        return ans << 1;
    }
};
