/**
 * @brief Deep clone graph using DFS with memoization
 * @intuition Map original nodes to clones, recursively clone neighbors
 * @approach DFS with hash map to track already-cloned nodes
 * @complexity Time: O(V+E), Space: O(V)
 */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto cloneGraph(Node* node) -> Node* {
        unordered_map<Node*, Node*> cloned;

        auto dfs = [&](this auto&& dfs, Node* original) -> Node* {
            if (!original) {
                return nullptr;
            }
            if (cloned.contains(original)) {
                return cloned[original];
            }

            auto* clone = new Node(original->val);
            cloned[original] = clone;

            for (auto* neighbor : original->neighbors) {
                clone->neighbors.push_back(dfs(neighbor));
            }
            return clone;
        };

        return dfs(node);
    }
};
