/**
 * @brief Calculate total poison duration from attack times
 * @intuition Each attack adds min(duration, gap to next attack)
 * @approach Sum min of duration and time gaps between attacks
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findPoisonedDuration(const std::vector<int>& timeSeries,
                                             int duration) const -> int {
        int ans = duration;
        const int n = static_cast<int>(timeSeries.size());

        for (int i = 1; i < n; ++i) {
            ans += std::min(duration, timeSeries[i] - timeSeries[i - 1]);
        }

        return ans;
    }
};
