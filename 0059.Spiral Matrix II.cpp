/**
 * @brief Generate an n x n matrix filled in spiral order
 * @intuition Use direction vectors to navigate the spiral pattern
 * @approach Fill values 1 to n*n following right, down, left, up pattern
 * @complexity Time: O(n^2), Space: O(n^2)
 */

class Solution final {
public:
  [[nodiscard]] static auto generateMatrix(int const n) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    static constexpr int dirs[5] = {0, 1, 0, -1, 0};
    int row = 0;
    int col = 0;
    int dirIndex = 0;

    for (int val = 1; val <= n * n; ++val) {
      result[row][col] = val;
      int const nextRow = row + dirs[dirIndex];
      int const nextCol = col + dirs[dirIndex + 1];

      if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n ||
          result[nextRow][nextCol] != 0) {
        dirIndex = (dirIndex + 1) % 4;
      }

      row += dirs[dirIndex];
      col += dirs[dirIndex + 1];
    }

    return result;
  }
};
