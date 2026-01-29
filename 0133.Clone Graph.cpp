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

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution final {
public:
    [[nodiscard]] auto cloneGraph(Node* node) const -> Node* {
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
