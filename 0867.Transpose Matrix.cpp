/**
 * @brief Create new matrix with rows and columns swapped
 * @intuition Transpose swaps element at (i,j) to (j,i)
 * @approach Create result matrix with swapped dimensions. Copy elements
 *           with indices transposed.
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto transpose(
        const std::vector<std::vector<int>>& matrix)
        -> std::vector<std::vector<int>> {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> ans(n, std::vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
