/**
 * @brief Digit DP to count occurrences of digit 1
 * @intuition Count 1s at each digit position using memoization
 * @approach Recursive digit DP with memoization tracking count of 1s
 * @complexity Time: O(log n * log n), Space: O(log n * log n)
 */

class Solution final {
public:
  [[nodiscard]] static auto countDigitOne(const int n) -> int {
    const std::string digits = std::to_string(n);
    const int len = static_cast<int>(digits.size());
    std::vector<std::vector<int>> memo(len, std::vector<int>(len, -1));
    
    std::function<int(int, int, bool)> dfs = [&](const int pos, const int count, const bool limit) -> int {
      if (pos >= len) {
        return count;
      }
      if (!limit && memo[pos][count] != -1) {
        return memo[pos][count];
      }
      const int upperBound = limit ? digits[pos] - '0' : 9;
      int result = 0;
      for (int digit = 0; digit <= upperBound; ++digit) {
        result += dfs(pos + 1, count + (digit == 1), limit && digit == upperBound);
      }
      if (!limit) {
        memo[pos][count] = result;
      }
      return result;
    };
    
    return dfs(0, 0, true);
  }
};
