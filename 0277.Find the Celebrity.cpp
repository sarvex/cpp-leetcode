/**
 * @brief Two-pass algorithm to find celebrity
 * @intuition Celebrity knows no one and everyone knows celebrity
 * @approach First pass finds candidate, second pass verifies
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] auto findCelebrity(const int n) const -> int {
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
      if (knows(candidate, i)) {
        candidate = i;
      }
    }
    
    for (int i = 0; i < n; ++i) {
      if (candidate != i) {
        if (knows(candidate, i) || !knows(i, candidate)) {
          return -1;
        }
      }
    }
    return candidate;
  }
};
