/**
 * @brief Sparse matrix multiplication
 * @intuition Standard matrix multiplication with sparse optimization potential
 * @approach Triple nested loop for matrix multiplication
 * @complexity Time: O(m * n * k), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> multiply(
        const vector<vector<int>>& mat1,
        const vector<vector<int>>& mat2) {
        
        const int m = static_cast<int>(mat1.size());
        const int k = static_cast<int>(mat2.size());
        const int n = static_cast<int>(mat2[0].size());
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int p = 0; p < k; ++p) {
                if (mat1[i][p] == 0) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    ans[i][j] += mat1[i][p] * mat2[p][j];
                }
            }
        }
        return ans;
    }
};
