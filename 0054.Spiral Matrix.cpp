#include <vector>
#include <array>

class Solution final {
public:
/**
 * @brief Traverses a 2D matrix in spiral order
 *
 * @intuition Use direction vectors to move right, down, left, and up in order.
 * Change direction when hitting boundaries or visited cells.
 *
 * @approach Maintain current position and direction. Mark visited cells and
 * change direction when necessary. Stop after visiting all cells.
 *
 * @complexity
 *      Time:   O(m*n), where m and n are matrix dimensions
 *      Space:  O(m*n) for visited matrix, O(1) additional space
 */
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        const int rows = matrix.size();
        const int cols = matrix[0].size();
        std::vector<int> result;
        result.reserve(rows * cols);

        // Directions: right, down, left, up
        constexpr std::array<std::pair<int, int>, 4> directions = {{
            {0, 1},   // right
            {1, 0},   // down
            {0, -1},  // left
            {-1, 0}   // up
        }};

        // Visited matrix
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        int direction_index = 0;
        int row = 0, col = 0;

        for (int i = 0; i < rows * cols; ++i) {
            result.push_back(matrix[row][col]);
            visited[row][col] = true;

            // Calculate next position
            int next_row = row + directions[direction_index].first;
            int next_col = col + directions[direction_index].second;

            // Change direction if next position is out of bounds or already visited
            if (next_row < 0 || next_row >= rows ||
                next_col < 0 || next_col >= cols ||
                visited[next_row][next_col]) {
                direction_index = (direction_index + 1) % 4;
            }

            // Move to next position
            row += directions[direction_index].first;
            col += directions[direction_index].second;
        }

        return result;
    }
};
