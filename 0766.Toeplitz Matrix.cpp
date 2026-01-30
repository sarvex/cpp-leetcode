/**
 * @brief Check if matrix is Toeplitz (each diagonal has same elements)
 * @intuition Every element should equal its top-left neighbor
 * @approach Compare each element with element at (i-1, j-1)
 * @complexity Time: O(m*n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
