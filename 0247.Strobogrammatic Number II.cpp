/**
 * @brief Generate all n-digit strobogrammatic numbers
 * @intuition Build from center outward using valid strobogrammatic pairs
 * @approach Recursive generation adding symmetric pairs around middle
 * @complexity Time: O(5^(n/2)), Space: O(5^(n/2))
 */
#include <functional>
#include <string>
#include <utility>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto findStrobogrammatic(int n) const -> std::vector<std::string> {
    const std::vector<std::pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    
    std::function<std::vector<std::string>(int)> dfs = [&](int len) -> std::vector<std::string> {
      if (len == 0) {
        return {""};
      }
      if (len == 1) {
        return {"0", "1", "8"};
      }
      
      std::vector<std::string> result;
      for (const auto& inner : dfs(len - 2)) {
        for (const auto& [left, right] : pairs) {
          result.push_back(left + inner + right);
        }
        if (len != n) {
          result.push_back('0' + inner + '0');
        }
      }
      return result;
    };
    
    return dfs(n);
  }
};
