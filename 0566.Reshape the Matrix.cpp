/**
 * @brief Reshape matrix to new dimensions if element count matches
 * @intuition Flatten conceptually, remap indices: flat_idx -> (row, col) in both shapes
 * @approach For each position in flat array, compute source and dest indices
 * @complexity Time: O(m*n), Space: O(r*c)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> matrixReshape(
            const vector<vector<int>>& mat, const int r, const int c) {
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat[0].size());
        
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        
        return ans;
    }
};
