/**
 * @brief Find maximum gap using bucket sort (Pigeonhole principle)
 * @intuition Max gap >= (max-min)/(n-1), so bucket by this size to find gap between buckets
 * @approach Create buckets, track min/max in each, max gap is between adjacent non-empty buckets
 * @complexity Time: O(n), Space: O(n)
 */

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

using std::pair;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto maximumGap(vector<int>& nums) const -> int {
        const int n = static_cast<int>(nums.size());
        if (n < 2) {
            return 0;
        }
        
        constexpr int INF = std::numeric_limits<int>::max();
        int minVal = INF;
        int maxVal = -INF;
        
        for (const int v : nums) {
            minVal = std::min(minVal, v);
            maxVal = std::max(maxVal, v);
        }
        
        const int bucketSize = std::max(1, (maxVal - minVal) / (n - 1));
        const int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        // Each bucket stores (min, max) values
        vector<pair<int, int>> buckets(bucketCount, {INF, -INF});
        
        for (const int v : nums) {
            const int idx = (v - minVal) / bucketSize;
            buckets[idx].first = std::min(buckets[idx].first, v);
            buckets[idx].second = std::max(buckets[idx].second, v);
        }
        
        int maxGap = 0;
        int prevMax = INF;
        
        for (const auto& [curMin, curMax] : buckets) {
            if (curMin > curMax) {
                continue;  // Empty bucket
            }
            maxGap = std::max(maxGap, curMin - prevMax);
            prevMax = curMax;
        }
        
        return maxGap;
    }
};
