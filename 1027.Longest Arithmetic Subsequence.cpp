/**
 * @brief DP tracking arithmetic sequences by difference
 * @intuition For each pair, extend or start arithmetic sequence with that difference
 * @approach f[i][d] = length of longest arithmetic subsequence ending at i with difference d
 * @complexity Time: O(n^2), Space: O(n * D) where D = value range
 */
class Solution final {
public:
    [[nodiscard]] static int longestArithSeqLength(const vector<int>& nums) {
        const int n = nums.size();
        int f[n][1001];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                const int j = nums[i] - nums[k] + 500;
                f[i][j] = max(f[i][j], f[k][j] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        return ans + 1;
    }
};
