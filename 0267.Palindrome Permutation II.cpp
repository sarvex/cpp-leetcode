/**
 * @brief Generate all palindrome permutations using backtracking
 * @intuition Build palindrome from center, use half characters on each side
 * @approach Find middle char (if any), backtrack to generate permutations
 * @complexity Time: O((n/2)!), Space: O(n)
 */
#include <string>
#include <unordered_map>
#include <vector>

class Solution final {
private:
  std::size_t targetLength;
  std::vector<std::string> result;
  std::unordered_map<char, int> charCount;

  auto dfs(std::string& current) -> void {
    if (current.size() == targetLength) {
      result.push_back(current);
      return;
    }
    for (auto& [ch, count] : charCount) {
      if (count > 1) {
        count -= 2;
        const std::string newStr = ch + current + ch;
        dfs(const_cast<std::string&>(newStr));
        count += 2;
      }
    }
  }

public:
  [[nodiscard]] auto generatePalindromes(const std::string& s) -> std::vector<std::string> {
    targetLength = s.size();
    result.clear();
    charCount.clear();
    
    for (const char c : s) {
      ++charCount[c];
    }
    
    std::string middle;
    for (const auto& [ch, count] : charCount) {
      if (count & 1) {
        if (!middle.empty()) {
          return result;
        }
        middle = ch;
      }
    }
    
    dfs(middle);
    return result;
  }
};
