/**
 * @brief 2D prefix sum with 1D subarray sum counting
 * @intuition Fix top and bottom rows, reduce to 1D subarray sum problem
 * @approach For each row pair, compute column sums and count target subarrays
 * @complexity Time: O(m^2 * n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int numSubmatrixSumTarget(const vector<vector<int>>& matrix, const int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> col(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    col[k] += matrix[j][k];
                }
                ans += countSubarrays(col, target);
            }
        }
        return ans;
    }

private:
    [[nodiscard]] static int countSubarrays(const vector<int>& nums, const int target) {
        unordered_map<int, int> d{{0, 1}};
        int cnt = 0, s = 0;
        for (const int x : nums) {
            s += x;
            if (d.contains(s - target)) {
                cnt += d[s - target];
            }
            ++d[s];
        }
        return cnt;
    }
};
