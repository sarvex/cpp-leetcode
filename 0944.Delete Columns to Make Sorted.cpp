/**
 * @brief Count columns to delete for sorted columns
 * @intuition Column is unsorted if any adjacent pair is decreasing
 * @approach Check each column; count those with any out-of-order pair
 * @complexity Time: O(n * m), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minDeletionSize(const vector<string>& strs) {
        const int m = static_cast<int>(strs[0].size()), n = static_cast<int>(strs.size());
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
