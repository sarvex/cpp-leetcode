/**
 * @brief Count black pixels in rows with exactly N same-pattern black pixels
 * @intuition Valid pixels must be in columns with exactly N black pixels, all in identical rows
 * @approach Track black pixel count per row and column positions per column.
 *           For each column, check if first row has target count, column has same count,
 *           and all rows in column are identical. Add target to answer if valid.
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findBlackPixel(const vector<vector<char>>& picture, 
                                              int target) -> int {
        const int m = static_cast<int>(picture.size());
        const int n = static_cast<int>(picture[0].size());
        
        vector<vector<int>> colRows(n);
        vector<int> rowCount(m, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rowCount[i];
                    colRows[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (colRows[j].empty() || rowCount[colRows[j][0]] != target) {
                continue;
            }
            
            const int firstRow = colRows[j][0];
            int validCount = 0;
            
            if (static_cast<int>(colRows[j].size()) == rowCount[firstRow]) {
                validCount = target;
                for (int row : colRows[j]) {
                    if (picture[firstRow] != picture[row]) {
                        validCount = 0;
                        break;
                    }
                }
            }
            ans += validCount;
        }
        return ans;
    }
};
