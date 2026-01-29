/**
 * @brief Topological sort for alien dictionary order
 * @intuition Build directed graph from word comparisons, topological sort gives order
 * @approach Compare adjacent words to find edges, use BFS topological sort
 * @complexity Time: O(C) where C is total characters, Space: O(1) for 26 letters
 */
#include <array>
#include <queue>
#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto alienOrder(const std::vector<std::string>& words) const -> std::string {
    std::array<std::array<bool, 26>, 26> graph{};
    std::array<bool, 26> exists{};
    int charCount = 0;
    const auto n = words.size();
    
    for (std::size_t i = 0; i < n - 1; ++i) {
      for (const char c : words[i]) {
        if (charCount == 26) break;
        const int idx = c - 'a';
        if (!exists[idx]) {
          ++charCount;
          exists[idx] = true;
        }
      }
      const auto& word1 = words[i];
      const auto& word2 = words[i + 1];
      for (std::size_t j = 0; j < word1.size(); ++j) {
        if (j >= word2.size()) {
          return "";
        }
        if (word1[j] != word2[j]) {
          const int from = word1[j] - 'a';
          const int to = word2[j] - 'a';
          if (graph[to][from]) {
            return "";
          }
          graph[from][to] = true;
          break;
        }
      }
    }
    
    for (const char c : words[n - 1]) {
      if (charCount == 26) break;
      const int idx = c - 'a';
      if (!exists[idx]) {
        ++charCount;
        exists[idx] = true;
      }
    }
    
    std::array<int, 26> indegree{};
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (i != j && exists[i] && exists[j] && graph[i][j]) {
          ++indegree[j];
        }
      }
    }
    
    std::queue<int> q;
    for (int i = 0; i < 26; ++i) {
      if (exists[i] && indegree[i] == 0) {
        q.push(i);
      }
    }
    
    std::string result;
    while (!q.empty()) {
      const int curr = q.front();
      q.pop();
      result += static_cast<char>(curr + 'a');
      for (int i = 0; i < 26; ++i) {
        if (i != curr && exists[i] && graph[curr][i]) {
          if (--indegree[i] == 0) {
            q.push(i);
          }
        }
      }
    }
    
    return result.size() < static_cast<std::size_t>(charCount) ? "" : result;
  }
};
