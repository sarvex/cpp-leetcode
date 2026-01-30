/**
 * @brief Dynamic programming for maximal square in matrix
 * @intuition dp[i][j] represents side length of max square ending at (i-1, j-1)
 * @approach Take minimum of three neighbors plus one when cell is '1'
 * @complexity Time: O(m*n), Space: O(m*n)
 */

class Solution final {
public:
    [[nodiscard]] static auto maximalSquare(const std::vector<std::vector<char>>& matrix) -> int {
        const auto rows = matrix.size();
        const auto cols = matrix[0].size();
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
        int maxSide = 0;
        
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = std::min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    maxSide = std::max(maxSide, dp[i + 1][j + 1]);
                }
            }
        }
        
        return maxSide * maxSide;
    }
};
