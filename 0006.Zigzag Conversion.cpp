/**
 * @brief Zigzag conversion of a string using row-wise simulation
 * @intuition Simulate the zigzag pattern by distributing characters row by row
 * @approach Use a vector of strings to collect characters for each row
 * @complexity Time: O(n), Space: O(n)
 */

#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto convert(const std::string& s, const int numRows)
      -> std::string {
    if (numRows <= 1 || static_cast<size_t>(numRows) >= s.size()) {
      return s;
    }

    std::vector<std::string> rows(numRows);
    int row = 0;
    int step = 1;

    for (const char c : s) {
      rows[row] += c;
      if (row == 0) {
        step = 1;
      } else if (row == numRows - 1) {
        step = -1;
      }
      row += step;
    }

    std::string result;
    for (const auto& r : rows) {
      result += r;
    }

    return result;
  }
};
