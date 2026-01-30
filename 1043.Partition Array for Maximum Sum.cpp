/**
 * @brief DP partitioning with maximum element per segment
 * @intuition Partition into segments of length <= k, fill each with its max
 * @approach f[i] = max sum for first i elements; try all segment lengths up to k
 * @complexity Time: O(n * k), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxSumAfterPartitioning(const vector<int>& arr, const int k) {
        const int n = arr.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > max(0, i - k); --j) {
                mx = max(mx, arr[j - 1]);
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
};
