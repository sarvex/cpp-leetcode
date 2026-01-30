/**
 * @brief Check if matchsticks can form a square
 * @intuition Sum must be divisible by 4, DFS to distribute matchsticks to 4 sides
 * @approach Sort descending for pruning, backtrack with skip for equal edges
 * @complexity Time: O(4^n), Space: O(n)
 */
#include <algorithm>
#include <functional>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto makesquare(std::vector<int>& matchsticks) const -> bool {
        int sum = 0;
        int maxVal = 0;

        for (const int v : matchsticks) {
            sum += v;
            maxVal = std::max(maxVal, v);
        }

        const int side = sum / 4;
        if (sum % 4 != 0 || side < maxVal) {
            return false;
        }

        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<>());
        std::vector<int> edges(4, 0);

        return dfs(0, side, matchsticks, edges);
    }

private:
    [[nodiscard]] auto dfs(int idx, int target, const std::vector<int>& matchsticks,
                           std::vector<int>& edges) const -> bool {
        if (idx == static_cast<int>(matchsticks.size())) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            if (i > 0 && edges[i - 1] == edges[i]) {
                continue;
            }
            edges[i] += matchsticks[idx];
            if (edges[i] <= target && dfs(idx + 1, target, matchsticks, edges)) {
                return true;
            }
            edges[i] -= matchsticks[idx];
        }

        return false;
    }
};
