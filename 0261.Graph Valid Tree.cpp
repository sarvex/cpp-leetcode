/**
 * @brief Union-Find to verify graph is a valid tree
 * @intuition A valid tree has n-1 edges and no cycles
 * @approach Use Union-Find to detect cycles while processing edges
 * @complexity Time: O(n * α(n)), Space: O(n)
 */
#include <functional>
#include <numeric>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto validTree(int n, const std::vector<std::vector<int>>& edges) const -> bool {
    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);
    
    std::function<int(int)> find = [&](int x) -> int {
      if (parent[x] != x) {
        parent[x] = find(parent[x]);
      }
      return parent[x];
    };
    
    int components = n;
    for (const auto& edge : edges) {
      const int rootA = find(edge[0]);
      const int rootB = find(edge[1]);
      if (rootA == rootB) {
        return false;
      }
      parent[rootA] = rootB;
      --components;
    }
    return components == 1;
  }
};
