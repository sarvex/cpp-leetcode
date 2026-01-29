/**
 * @brief Validate if a string represents a valid number
 * @intuition Track state for signs, dots, and exponents while iterating
 * @approach Parse string character by character, validating transitions
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto isNumber(std::string const& s) -> bool {
    int const n = static_cast<int>(s.size());
    int i = 0;

    if (s[i] == '+' || s[i] == '-') {
      ++i;
    }

    if (i == n) {
      return false;
    }

    if (s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) {
      return false;
    }

    int dot = 0;
    int e = 0;

    for (int j = i; j < n; ++j) {
      if (s[j] == '.') {
        if (e != 0 || dot != 0) {
          return false;
        }
        ++dot;
      } else if (s[j] == 'e' || s[j] == 'E') {
        if (e != 0 || j == i || j == n - 1) {
          return false;
        }
        ++e;
        if (s[j + 1] == '+' || s[j + 1] == '-') {
          if (++j == n - 1) {
            return false;
          }
        }
      } else if (s[j] < '0' || s[j] > '9') {
        return false;
      }
    }

    return true;
  }
};
