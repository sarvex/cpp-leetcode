/**
 * @brief Greedy sorting by cost difference
 * @intuition Sort by benefit of choosing city A over B, send first half to A
 * @approach Sort by (costA - costB), assign first n to A, rest to B
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        const int n = costs.size() / 2;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
};
