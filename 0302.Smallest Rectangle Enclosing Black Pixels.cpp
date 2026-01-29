/**
 * @brief Binary search to find smallest rectangle enclosing black pixels
 * @intuition Given one black pixel, use binary search to find boundaries
 * @approach Binary search on rows/columns to find first/last black pixels
 * @complexity Time: O(m log n + n log m), Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] int minArea(std::vector<std::vector<char>>& image, int x, int y) const {
        const int m = static_cast<int>(image.size());
        const int n = static_cast<int>(image[0].size());
        
        // Find top boundary
        int left = 0;
        int right = x;
        while (left < right) {
            const int mid = (left + right) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const int top = left;
        
        // Find bottom boundary
        left = x;
        right = m - 1;
        while (left < right) {
            const int mid = (left + right + 1) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        const int bottom = left;
        
        // Find left boundary
        left = 0;
        right = y;
        while (left < right) {
            const int mid = (left + right) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const int leftBound = left;
        
        // Find right boundary
        left = y;
        right = n - 1;
        while (left < right) {
            const int mid = (left + right + 1) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        const int rightBound = left;
        
        return (bottom - top + 1) * (rightBound - leftBound + 1);
    }
};
