/**
 * @brief Sparse matrix multiplication
 * @intuition Standard matrix multiplication with sparse optimization potential
 * @approach Triple nested loop for matrix multiplication
 * @complexity Time: O(m * n * k), Space: O(m * n)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<std::vector<int>> multiply(
        const std::vector<std::vector<int>>& mat1,
        const std::vector<std::vector<int>>& mat2) const {
        
        const int m = static_cast<int>(mat1.size());
        const int k = static_cast<int>(mat2.size());
        const int n = static_cast<int>(mat2[0].size());
        
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int p = 0; p < k; ++p) {
                    ans[i][j] += mat1[i][p] * mat2[p][j];
                }
            }
        }
        return ans;
    }
};
