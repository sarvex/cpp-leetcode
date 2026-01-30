/**
 * @brief Apply 3x3 average filter to image
 * @intuition For each cell, average all valid neighbors including itself
 * @approach Iterate 3x3 window around each cell, handle boundary conditions
 * @complexity Time: O(m * n), Space: O(m * n) for output
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> imageSmoother(const vector<vector<int>>& img) {
        const int m = img.size();
        const int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0, cnt = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            ++cnt;
                            s += img[x][y];
                        }
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
};
