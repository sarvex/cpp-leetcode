/**
 * @brief Greedy selection of floor/ceil to minimize rounding error
 * @intuition Floor all first, then greedily ceil those with largest decimal parts
 * @approach Sort by decimal part descending, ceil top (target - floor_sum) values
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string minimizeError(const vector<string>& prices, const int target) {
        int mi = 0;
        vector<double> arr;
        for (const auto& p : prices) {
            const double price = stod(p);
            mi += static_cast<int>(price);
            const double d = price - static_cast<int>(price);
            if (d > 0) {
                arr.push_back(d);
            }
        }
        if (target < mi || target > mi + static_cast<int>(arr.size())) {
            return "-1";
        }
        const int d = target - mi;
        sort(arr.rbegin(), arr.rend());
        double ans = d;
        for (int i = 0; i < d; ++i) {
            ans -= arr[i];
        }
        for (int i = d; i < static_cast<int>(arr.size()); ++i) {
            ans += arr[i];
        }
        string s = to_string(ans);
        return s.substr(0, s.find('.') + 4);
    }
};
