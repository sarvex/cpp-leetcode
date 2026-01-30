/**
 * @brief Binary search to find first bad version
 * @intuition All versions after first bad are also bad
 * @approach Binary search to find leftmost bad version
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] auto firstBadVersion(const int n) const -> int {
    int left = 1;
    int right = n;
    
    while (left < right) {
      const int mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
