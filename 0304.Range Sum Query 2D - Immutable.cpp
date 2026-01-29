/**
 * @brief 2D prefix sum for immutable region sum queries
 * @intuition Precompute 2D prefix sums using inclusion-exclusion
 * @approach Build 2D prefix sum matrix, then query using inclusion-exclusion formula
 * @complexity Time: O(mn) build, O(1) query, Space: O(mn)
 */
#include <vector>

class NumMatrix final {
public:
    explicit NumMatrix(const std::vector<std::vector<int>>& matrix) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        prefix_sum_.resize(m + 1, std::vector<int>(n + 1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix_sum_[i + 1][j + 1] = prefix_sum_[i + 1][j] + prefix_sum_[i][j + 1] 
                                           - prefix_sum_[i][j] + matrix[i][j];
            }
        }
    }

    [[nodiscard]] int sumRegion(int row1, int col1, int row2, int col2) const {
        return prefix_sum_[row2 + 1][col2 + 1] - prefix_sum_[row2 + 1][col1] 
               - prefix_sum_[row1][col2 + 1] + prefix_sum_[row1][col1];
    }

private:
    std::vector<std::vector<int>> prefix_sum_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
