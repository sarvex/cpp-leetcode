/**
 * @brief Find length of longest valid parentheses substring using DP
 * @intuition Track valid substrings ending at each position
 * @approach Use DP table where dp[i] stores longest valid ending at i-1
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto longestValidParentheses(const std::string& s)
      -> int {
    const auto n = s.size();
    std::vector<int> dp(n + 1, 0);
    int maxLength = 0;

    for (size_t i = 2; i <= n; ++i) {
      if (s[i - 1] == ')') {
        if (s[i - 2] == '(') {
          dp[i] = dp[i - 2] + 2;
        } else if (i > static_cast<size_t>(dp[i - 1]) + 1 &&
                   s[i - dp[i - 1] - 2] == '(') {
          dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
        }
        maxLength = std::max(maxLength, dp[i]);
      }
    }

    return maxLength;
  }
};
