/**
 * @brief Find maximum distance between elements from different sorted arrays
 * @intuition Track running min and max, compare with each array's endpoints
 * @approach For each array, compute distance using previous min/max, then update
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxDistance(const vector<vector<int>>& arrays) {
        int ans = 0;
        int mi = arrays[0].front();
        int mx = arrays[0].back();
        
        for (size_t i = 1; i < arrays.size(); ++i) {
            const auto& arr = arrays[i];
            const int a = abs(arr.front() - mx);
            const int b = abs(arr.back() - mi);
            ans = max({ans, a, b});
            mi = min(mi, arr.front());
            mx = max(mx, arr.back());
        }
        return ans;
    }
};
