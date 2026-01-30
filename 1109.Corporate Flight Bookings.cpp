/**
 * @brief Difference array for range updates
 * @intuition Use difference array technique to efficiently handle range additions
 * @approach For each booking, add seats at start index and subtract at end+1. Then compute
 *           prefix sums to get actual seat counts for each flight.
 * @complexity Time: O(n + m) where m is bookings count, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> corpFlightBookings(const vector<vector<int>>& bookings, const int n) {
        vector<int> ans(n);
        for (const auto& e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            ans[first - 1] += seats;
            if (last < n) {
                ans[last] -= seats;
            }
        }
        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
