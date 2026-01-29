/**
 * @brief Traverse a 2D matrix in spiral order
 * @intuition Use direction vectors to move right, down, left, up in sequence
 * @approach Track visited cells, change direction when hitting boundaries or visited cells
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto spiralOrder(std::vector<std::vector<int>> const& matrix)
      -> std::vector<int> {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }

    int const rows = static_cast<int>(matrix.size());
    int const cols = static_cast<int>(matrix[0].size());
    std::vector<int> result;
    result.reserve(rows * cols);

    static constexpr std::array<std::pair<int, int>, 4> directions = {{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    }};

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    int dirIndex = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; i < rows * cols; ++i) {
      result.push_back(matrix[row][col]);
      visited[row][col] = true;

      int const nextRow = row + directions[dirIndex].first;
      int const nextCol = col + directions[dirIndex].second;

      if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols ||
          visited[nextRow][nextCol]) {
        dirIndex = (dirIndex + 1) % 4;
      }

      row += directions[dirIndex].first;
      col += directions[dirIndex].second;
    }

    return result;
  }
};
