/**
 * @brief Iterator for flattening 2D vector
 * @intuition Maintain row and column indices, advance to next valid element
 * @approach Skip empty rows lazily when accessing elements
 * @complexity Time: O(1) amortized per operation, Space: O(1) extra
 */
#include <utility>
#include <vector>

class Vector2D final {
private:
  std::vector<std::vector<int>> data;
  std::size_t row = 0;
  std::size_t col = 0;

  auto advance() -> void {
    while (row < data.size() && col >= data[row].size()) {
      ++row;
      col = 0;
    }
  }

public:
  explicit Vector2D(std::vector<std::vector<int>>& vec) : data(std::move(vec)) {}

  [[nodiscard]] auto next() -> int {
    advance();
    return data[row][col++];
  }

  [[nodiscard]] auto hasNext() -> bool {
    advance();
    return row < data.size();
  }
};
