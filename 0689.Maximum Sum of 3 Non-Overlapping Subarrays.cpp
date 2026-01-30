/**
 * @brief Find indices of 3 non-overlapping subarrays with maximum sum
 * @intuition Track best single, best pair, and best triple as we slide windows
 * @approach Maintain running sums for 3 windows, track optimal indices at each step
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> maxSumOfThreeSubarrays(const vector<int>& nums, const int k) {
        vector<int> ans(3);
        int s = 0;
        int s1 = 0, s2 = 0, s3 = 0;
        int mx1 = 0, mx12 = 0;
        int idx1 = 0, idx121 = 0, idx122 = 0;
        
        for (size_t i = k * 2; i < nums.size(); ++i) {
            s1 += nums[i - k * 2];
            s2 += nums[i - k];
            s3 += nums[i];
            
            if (i >= k * 3 - 1) {
                if (s1 > mx1) {
                    mx1 = s1;
                    idx1 = i - k * 3 + 1;
                }
                if (mx1 + s2 > mx12) {
                    mx12 = mx1 + s2;
                    idx121 = idx1;
                    idx122 = i - k * 2 + 1;
                }
                if (mx12 + s3 > s) {
                    s = mx12 + s3;
                    ans = {idx121, idx122, static_cast<int>(i - k + 1)};
                }
                s1 -= nums[i - k * 3 + 1];
                s2 -= nums[i - k * 2 + 1];
                s3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
