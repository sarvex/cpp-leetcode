/**
 * @brief Simulate champagne tower overflow
 * @intuition Each glass receives overflow from two glasses above
 * @approach DP simulation: track amount in each glass, distribute overflow
 * @complexity Time: O(query_row^2), Space: O(query_row^2)
 */
class Solution final {
public:
    [[nodiscard]] static double champagneTower(const int poured, 
                                                const int queryRow, 
                                                const int queryGlass) {
        std::vector<std::vector<double>> glasses(101, std::vector<double>(101, 0.0));
        glasses[0][0] = poured;
        
        for (int row = 0; row <= queryRow; ++row) {
            for (int col = 0; col <= row; ++col) {
                if (glasses[row][col] > 1.0) {
                    const double overflow = (glasses[row][col] - 1.0) / 2.0;
                    glasses[row][col] = 1.0;
                    glasses[row + 1][col] += overflow;
                    glasses[row + 1][col + 1] += overflow;
                }
            }
        }
        return glasses[queryRow][queryGlass];
    }
};
