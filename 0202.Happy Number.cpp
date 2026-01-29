/**
 * @brief Hash set cycle detection for happy numbers
 * @intuition A number is happy if the sum of squares of digits eventually equals 1
 * @approach Track seen numbers in a hash set to detect cycles
 * @complexity Time: O(log n) average, Space: O(log n) for the hash set
 */
#include <unordered_set>

class Solution final {
public:
  [[nodiscard]] auto isHappy(int n) const -> bool {
    std::unordered_set<int> visited;
    while (n != 1 && visited.find(n) == visited.end()) {
      visited.insert(n);
      int sum = 0;
      while (n > 0) {
        const int digit = n % 10;
        sum += digit * digit;
        n /= 10;
      }
      n = sum;
    }
    return n == 1;
  }
};
