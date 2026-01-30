/**
 * @brief Count number of longest increasing subsequences
 * @intuition Track both LIS length and count at each position
 * @approach DP: f[i] = LIS length ending at i, cnt[i] = count of such sequences
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findNumberOfLIS(const vector<int>& nums) {
        const int n = nums.size();
        int mx = 0, ans = 0;
        vector<int> f(n, 1);
        vector<int> cnt(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (f[i] == f[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (mx < f[i]) {
                mx = f[i];
                ans = cnt[i];
            } else if (mx == f[i]) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
