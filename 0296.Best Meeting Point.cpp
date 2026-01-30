/**
 * @brief Find best meeting point using median
 * @intuition Optimal meeting point is median of row/column coordinates
 * @approach Collect all coordinates, find median, sum distances
 * @complexity Time: O(mn), Space: O(mn)
 */
class Solution final {
public:
    [[nodiscard]] static int minTotalDistance(const vector<vector<int>>& grid) {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        vector<int> rows;
        vector<int> cols;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    rows.emplace_back(i);
                    cols.emplace_back(j);
                }
            }
        }
        
        sort(cols.begin(), cols.end());
        const int medianRow = rows[rows.size() / 2];
        const int medianCol = cols[cols.size() / 2];
        
        auto sumDistances = [](const vector<int>& arr, int target) {
            int sum = 0;
            for (const int v : arr) {
                sum += abs(v - target);
            }
            return sum;
        };
        
        return sumDistances(rows, medianRow) + sumDistances(cols, medianCol);
    }
};
