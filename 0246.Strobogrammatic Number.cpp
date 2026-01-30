/**
 * @brief Two-pointer validation for strobogrammatic numbers
 * @intuition Check if digits at symmetric positions form valid strobogrammatic pairs
 * @approach Use lookup table for valid 180-degree rotations
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto isStrobogrammatic(const std::string& num) -> bool {
    constexpr std::array<int, 10> rotation = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    
    for (std::size_t i = 0, j = num.size() - 1; i <= j; ++i, --j) {
      const int digitLeft = num[i] - '0';
      const int digitRight = num[j] - '0';
      if (rotation[digitLeft] != digitRight) {
        return false;
      }
    }
    return true;
  }
};
