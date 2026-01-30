/**
 * @brief Track last positions for shortest word distance
 * @intuition Update positions when words found, compute distance when both seen
 * @approach Single pass tracking indices of word1 and word2
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto shortestDistance(const std::vector<std::string>& wordsDict, 
                                              const std::string& word1, 
                                              const std::string& word2) -> int {
    int minDistance = INT_MAX;
    int idx1 = -1;
    int idx2 = -1;
    
    for (int k = 0; k < static_cast<int>(wordsDict.size()); ++k) {
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
    return minDistance;
  }
};
