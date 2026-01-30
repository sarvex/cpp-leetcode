/**
 * @brief Binary search for H-Index in sorted array
 * @intuition In sorted array, binary search for largest h where citations[n-h] >= h
 * @approach Use binary search to find maximum h satisfying the h-index condition
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static auto hIndex(const std::vector<int>& citations) -> int {
    const auto n = static_cast<int>(citations.size());
    int left = 0;
    int right = n;
    
    while (left < right) {
      const int mid = (left + right + 1) >> 1;
      if (citations[n - mid] >= mid) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};
