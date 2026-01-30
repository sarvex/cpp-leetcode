/**
 * @brief Binary search on ship capacity
 * @intuition Minimum capacity is max weight, maximum is sum; binary search valid range
 * @approach Binary search capacity, greedily check if shipment fits within days
 * @complexity Time: O(n log S) where S = sum of weights, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int shipWithinDays(const vector<int>& weights, const int days) {
        int left = 0, right = 0;
        for (const auto& w : weights) {
            left = max(left, w);
            right += w;
        }
        auto check = [&](const int mx) {
            int ws = 0, cnt = 1;
            for (const auto& w : weights) {
                ws += w;
                if (ws > mx) {
                    ws = w;
                    ++cnt;
                }
            }
            return cnt <= days;
        };
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
