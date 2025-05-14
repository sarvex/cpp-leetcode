#include <vector>

class Solution final {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::vector<std::vector<bool>> row(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> col(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> sub(9, std::vector<bool>(9, false));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.')
          continue;
        int num = c - '0' - 1;
        int k = i / 3 * 3 + j / 3;
        if (row[i][num] || col[j][num] || sub[k][num]) {
          return false;
        }
        row[i][num] = true;
        col[j][num] = true;
        sub[k][num] = true;
      }
    }
    return true;
  }
};
