/**
 * @brief Track maximum value + index while iterating
 * @intuition Score = values[i] + i + values[j] - j; track max of (values[i] + i)
 * @approach Iterate j, maintain max prefix contribution, update answer
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxScoreSightseeingPair(const vector<int>& values) {
        int ans = 0, mx = 0;
        for (int j = 0; j < static_cast<int>(values.size()); ++j) {
            ans = max(ans, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
