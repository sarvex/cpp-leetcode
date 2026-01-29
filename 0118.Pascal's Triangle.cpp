/**
 * @brief Generate Pascal's triangle row by row
 * @intuition Each element is sum of two elements above it
 * @approach Build each row from previous row, edges are always 1
 * @complexity Time: O(n^2), Space: O(n^2)
 */

class Solution final {
public:
    [[nodiscard]] static auto generate(int numRows) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> triangle;
        triangle.push_back({1});
        
        for (int i = 1; i < numRows; ++i) {
            std::vector<int> row;
            row.push_back(1);
            for (std::size_t j = 0; j < triangle[i - 1].size() - 1; ++j) {
                row.push_back(triangle[i - 1][j] + triangle[i - 1][j + 1]);
            }
            row.push_back(1);
            triangle.push_back(std::move(row));
        }
        
        return triangle;
    }
};
