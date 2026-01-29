/**
 * @brief Group strings by shift pattern
 * @intuition Strings in same group have same relative character differences
 * @approach Normalize each string by shifting first char to 'a', group by key
 * @complexity Time: O(n * m), Space: O(n * m) where m is average string length
 */
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto groupStrings(const std::vector<std::string>& strings) const 
      -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    
    for (const auto& s : strings) {
      std::string normalized;
      const int shift = s[0] - 'a';
      for (const char c : s) {
        char normalizedChar = static_cast<char>(c - shift);
        if (normalizedChar < 'a') {
          normalizedChar += 26;
        }
        normalized.push_back(normalizedChar);
      }
      groups[normalized].push_back(s);
    }
    
    std::vector<std::vector<std::string>> result;
    result.reserve(groups.size());
    for (auto& [key, group] : groups) {
      result.push_back(std::move(group));
    }
    return result;
  }
};
