/**
 * @brief Topological sort to find valid course order
 * @intuition Build dependency graph and process courses with no prerequisites first
 * @approach Kahn's algorithm: track indegrees, BFS from zero-indegree nodes
 * @complexity Time: O(V + E), Space: O(V + E)
 */
#include <queue>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) const -> std::vector<int> {
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> indegree(numCourses);
    
    for (const auto& prereq : prerequisites) {
      const auto course = prereq[0];
      const auto dependency = prereq[1];
      graph[dependency].push_back(course);
      ++indegree[course];
    }
    
    std::queue<int> readyQueue;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        readyQueue.push(i);
      }
    }
    
    std::vector<int> order;
    order.reserve(numCourses);
    
    while (!readyQueue.empty()) {
      const auto current = readyQueue.front();
      readyQueue.pop();
      order.push_back(current);
      for (const auto next : graph[current]) {
        if (--indegree[next] == 0) {
          readyQueue.push(next);
        }
      }
    }
    
    return order.size() == static_cast<std::size_t>(numCourses) ? order : std::vector<int>{};
  }
};
