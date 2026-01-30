/**
 * @brief Find k-th smallest in m x n multiplication table
 * @intuition Binary search on answer, count numbers <= mid
 * @approach For each row i, count how many <= mid is min(mid/i, n)
 * @complexity Time: O(m log(m*n)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int findKthNumber(const int m, const int n, const int k) {
        int left = 1, right = m * n;
        
        while (left < right) {
            const int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += min(mid / i, n);
            }
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
