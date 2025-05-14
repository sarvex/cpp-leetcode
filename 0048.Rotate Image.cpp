#include <algorithm>
#include <vector>

class Solution final {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n >> 1; ++i) {
      for (int j = 0; j < n; ++j) {
        std::swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
