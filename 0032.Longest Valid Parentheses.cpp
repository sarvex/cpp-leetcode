#include <algorithm>
#include <string>
#include <vector>

class Solution final {
public:
  /**
   * @brief Returns the length of the longest valid parentheses substring using dynamic programming.
   * @intuition: Track valid substrings ending at each position using a DP table.
   * @approach: For each ')', check if it closes a valid '('. Use dpTable[i] to store the length of the longest valid substring ending at i-1.
   * @complexity: Time: O(n)
   * @complexity: Space: O(n)
   */
  int longestValidParentheses(const std::string& parentheses) const {
    const auto stringLength = parentheses.size();
    std::vector<int> dpTable(stringLength + 1, 0);
    int longestLength = 0;
    for (size_t index = 2; index <= stringLength; ++index) {
      if (parentheses[index - 1] == ')') {
        if (parentheses[index - 2] == '(') {
          dpTable[index] = dpTable[index - 2] + 2;
        } else if (index > dpTable[index - 1] + 1 && parentheses[index - dpTable[index - 1] - 2] == '(') {
          dpTable[index] = dpTable[index - 1] + 2 + dpTable[index - dpTable[index - 1] - 2];
        }
        longestLength = std::max(longestLength, dpTable[index]);
      }
    }
    return longestLength;
  }
};
