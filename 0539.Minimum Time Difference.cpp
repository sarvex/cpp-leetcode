/**
 * @brief Find minimum time difference between any two time points
 * @intuition Convert to minutes, sort, check adjacent pairs and wrap-around
 * @approach Convert all times to minutes since midnight. Sort and compare adjacent pairs.
 *           Also check circular difference between last and first (adding 1440 minutes).
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findMinDifference(const vector<string>& timePoints) -> int {
        if (timePoints.size() > 1440) return 0;
        
        const int n = static_cast<int>(timePoints.size());
        vector<int> minutes(n + 1);
        
        for (int i = 0; i < n; ++i) {
            const int hours = stoi(timePoints[i].substr(0, 2));
            const int mins = stoi(timePoints[i].substr(3, 2));
            minutes[i] = hours * 60 + mins;
        }
        
        ranges::sort(minutes.begin(), minutes.begin() + n);
        minutes[n] = minutes[0] + 1440;
        
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        return ans;
    }
};
