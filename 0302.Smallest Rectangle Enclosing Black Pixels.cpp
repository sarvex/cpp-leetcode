/**
 * @brief Binary search to find smallest rectangle enclosing black pixels
 * @intuition Given one black pixel, use binary search to find boundaries
 * @approach Binary search on rows/columns to find first/last black pixels
 * @complexity Time: O(m log n + n log m), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minArea(const vector<vector<char>>& image, int x, int y) {
        const int m = static_cast<int>(image.size());
        const int n = static_cast<int>(image[0].size());
        
        auto hasBlackInRow = [&](int row) {
            for (int c = 0; c < n; ++c) {
                if (image[row][c] == '1') {
                    return true;
                }
            }
            return false;
        };
        
        auto hasBlackInCol = [&](int col) {
            for (int r = 0; r < m; ++r) {
                if (image[r][col] == '1') {
                    return true;
                }
            }
            return false;
        };
        
        int left = 0, right = x;
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (hasBlackInRow(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const int top = left;
        
        left = x;
        right = m - 1;
        while (left < right) {
            const int mid = (left + right + 1) >> 1;
            if (hasBlackInRow(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        const int bottom = left;
        
        left = 0;
        right = y;
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (hasBlackInCol(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const int leftBound = left;
        
        left = y;
        right = n - 1;
        while (left < right) {
            const int mid = (left + right + 1) >> 1;
            if (hasBlackInCol(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        const int rightBound = left;
        
        return (bottom - top + 1) * (rightBound - leftBound + 1);
    }
};
