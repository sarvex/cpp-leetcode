/**
 * @brief Topological sort using Kahn's algorithm (BFS)
 * @intuition Course schedule is valid if no cycle exists in dependency graph
 * @approach Build graph, track indegrees, process nodes with zero indegree
 * @complexity Time: O(V + E), Space: O(V + E)
 */
#include <queue>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) const -> bool {
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
    
    int completedCount = 0;
    while (!readyQueue.empty()) {
      const auto current = readyQueue.front();
      readyQueue.pop();
      ++completedCount;
      for (const auto next : graph[current]) {
        if (--indegree[next] == 0) {
          readyQueue.push(next);
        }
      }
    }
    
    return completedCount == numCourses;
  }
};
