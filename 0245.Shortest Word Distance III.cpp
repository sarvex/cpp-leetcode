/**
 * @brief Shortest word distance allowing same word
 * @intuition Handle same word case separately by tracking previous occurrence
 * @approach Different logic when word1 equals word2
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto shortestWordDistance(const std::vector<std::string>& wordsDict,
                                           const std::string& word1,
                                           const std::string& word2) const -> int {
    const auto n = static_cast<int>(wordsDict.size());
    int minDistance = n;
    
    if (word1 == word2) {
      int prevIdx = -1;
      for (int i = 0; i < n; ++i) {
        if (wordsDict[i] == word1) {
          if (prevIdx != -1) {
            minDistance = std::min(minDistance, i - prevIdx);
          }
          prevIdx = i;
        }
      }
    } else {
      int idx1 = -1;
      int idx2 = -1;
      for (int k = 0; k < n; ++k) {
        if (wordsDict[k] == word1) {
          idx1 = k;
        }
        if (wordsDict[k] == word2) {
          idx2 = k;
        }
        if (idx1 != -1 && idx2 != -1) {
          minDistance = std::min(minDistance, std::abs(idx1 - idx2));
        }
      }
    }
    return minDistance;
  }
};
