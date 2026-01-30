/**
 * @brief Calculate diet score using sliding window of k consecutive days
 * @intuition Compare k-day window sums against thresholds using prefix sums
 * @approach Build prefix sum array. For each k-day window, check if sum is below lower
 *           (subtract 1) or above upper (add 1).
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int dietPlanPerformance(const vector<int>& calories, const int k,
                                                  const int lower, const int upper) {
        const int n = calories.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + calories[i];
        }
        int ans = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            int t = s[i + k] - s[i];
            if (t < lower) {
                --ans;
            } else if (t > upper) {
                ++ans;
            }
        }
        return ans;
    }
};
