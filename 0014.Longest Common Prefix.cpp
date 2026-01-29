/**
 * @brief Find the longest common prefix among an array of strings
 * @intuition Compare characters column by column across all strings
 * @approach Use the first string as reference, check each position against others
 * @complexity Time: O(S) where S is sum of all characters, Space: O(1)
 */

#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto longestCommonPrefix(const std::vector<std::string>& strs)
      -> std::string {
    if (strs.empty()) {
      return "";
    }

    const auto n = strs.size();
    for (size_t i = 0; i < strs[0].size(); ++i) {
      for (size_t j = 1; j < n; ++j) {
        if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
    }

    return strs[0];
  }
};
