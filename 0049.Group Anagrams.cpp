/**
 * @brief Group strings by their anagram signature
 * @intuition Anagrams have the same sorted character sequence
 * @approach Use sorted string as key in hash map
 * @complexity Time: O(n * k log k), Space: O(n * k) where k is max string length
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto groupAnagrams(std::vector<std::string>& strs) const
      -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> groups;

    for (auto& s : strs) {
      std::string key = s;
      std::sort(key.begin(), key.end());
      groups[key].emplace_back(s);
    }

    std::vector<std::vector<std::string>> result;
    result.reserve(groups.size());

    for (auto& [_, group] : groups) {
      result.emplace_back(std::move(group));
    }

    return result;
  }
};
