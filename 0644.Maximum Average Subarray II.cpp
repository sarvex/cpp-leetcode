/**
 * @brief Find maximum average of subarray with length >= k
 * @intuition Binary search on answer, check if subarray with avg >= mid exists
 * @approach Binary search average, use prefix sums to verify feasibility
 * @complexity Time: O(n log(max-min)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static double findMaxAverage(const vector<int>& nums, const int k) {
        constexpr double eps = 1e-5;
        double l = *ranges::min_element(nums);
        double r = *ranges::max_element(nums);
        
        auto check = [&](double v) {
            double s = 0;
            for (int i = 0; i < k; ++i) {
                s += nums[i] - v;
            }
            if (s >= 0) {
                return true;
            }
            
            double t = 0;
            double mi = 0;
            for (size_t i = k; i < nums.size(); ++i) {
                s += nums[i] - v;
                t += nums[i - k] - v;
                mi = min(mi, t);
                if (s >= mi) {
                    return true;
                }
            }
            return false;
        };
        
        while (r - l >= eps) {
            const double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
