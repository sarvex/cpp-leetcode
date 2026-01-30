/**
 * @brief Find maximum average of subarray with length k
 * @intuition Sliding window: maintain sum of k elements, slide and track maximum
 * @approach Initialize window sum, slide right adding/removing elements
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static double findMaxAverage(const vector<int>& nums, const int k) {
        int s = accumulate(nums.begin(), nums.begin() + k, 0);
        int ans = s;
        
        for (size_t i = k; i < nums.size(); ++i) {
            s += nums[i] - nums[i - k];
            ans = max(ans, s);
        }
        return static_cast<double>(ans) / k;
    }
};
