/**
 * @brief Find minimum heater radius to warm all houses
 * @intuition Binary search on radius, check if all houses can be covered
 * @approach Sort both arrays, for each radius verify all houses are within range
 * @complexity Time: O((m + n) log(max)), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findRadius(std::vector<int>& houses, std::vector<int>& heaters) const -> int {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        int left = 0;
        int right = 1'000'000'000;

        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (canCover(houses, heaters, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    [[nodiscard]] static auto canCover(const std::vector<int>& houses,
                                        const std::vector<int>& heaters, int radius) -> bool {
        const int m = static_cast<int>(houses.size());
        const int n = static_cast<int>(heaters.size());
        int i = 0;
        int j = 0;

        while (i < m) {
            if (j >= n) {
                return false;
            }
            const int minCover = heaters[j] - radius;
            const int maxCover = heaters[j] + radius;
            if (houses[i] < minCover) {
                return false;
            }
            if (houses[i] > maxCover) {
                ++j;
            } else {
                ++i;
            }
        }

        return true;
    }
};
