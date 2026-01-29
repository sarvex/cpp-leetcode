/**
 * @brief Precomputed word positions for repeated shortest distance queries
 * @intuition Store indices for each word, use two-pointer for distance
 * @approach Build index map, merge sorted indices to find minimum distance
 * @complexity Time: O(n) build, O(a + b) query, Space: O(n)
 */
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

class WordDistance final {
private:
  std::unordered_map<std::string, std::vector<int>> positions;

public:
  explicit WordDistance(const std::vector<std::string>& wordsDict) {
    for (int i = 0; i < static_cast<int>(wordsDict.size()); ++i) {
      positions[wordsDict[i]].push_back(i);
    }
  }

  [[nodiscard]] auto shortest(const std::string& word1, const std::string& word2) const -> int {
    const auto& indices1 = positions.at(word1);
    const auto& indices2 = positions.at(word2);
    
    int minDistance = INT_MAX;
    std::size_t i = 0;
    std::size_t j = 0;
    
    while (i < indices1.size() && j < indices2.size()) {
      minDistance = std::min(minDistance, std::abs(indices1[i] - indices2[j]));
      if (indices1[i] <= indices2[j]) {
        ++i;
      } else {
        ++j;
      }
    }
    return minDistance;
  }
};
