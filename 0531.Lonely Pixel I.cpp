/**
 * @brief Count lonely black pixels in picture
 * @intuition A pixel is lonely if it's the only black pixel in its row and column
 * @approach First pass: count black pixels per row and column.
 *           Second pass: count black pixels where row count = 1 and column count = 1.
 * @complexity Time: O(m * n), Space: O(m + n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findLonelyPixel(const vector<vector<char>>& picture) -> int {
        const int m = static_cast<int>(picture.size());
        const int n = static_cast<int>(picture[0].size());
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
