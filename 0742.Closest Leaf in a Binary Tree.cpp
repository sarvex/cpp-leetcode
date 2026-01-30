/**
 * @brief Find closest leaf to node k in binary tree using BFS
 * @intuition Convert tree to undirected graph, BFS from k to find nearest leaf
 * @approach Build adjacency list from tree, BFS to find closest leaf node
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findClosestLeaf(TreeNode* root, const int k) {
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> graph;
        
        auto buildGraph = [&](auto&& self, TreeNode* node, TreeNode* parent) -> void {
            if (!node) return;
            graph[node].push_back(parent);
            graph[parent].push_back(node);
            self(self, node->left, node);
            self(self, node->right, node);
        };
        
        buildGraph(buildGraph, root, nullptr);
        
        std::queue<TreeNode*> queue;
        std::unordered_set<TreeNode*> visited;
        
        for (const auto& [node, _] : graph) {
            if (node && node->val == k) {
                queue.push(node);
                visited.insert(node);
                break;
            }
        }
        
        while (!queue.empty()) {
            auto* node = queue.front();
            queue.pop();
            if (node) {
                if (node->left == node->right) {
                    return node->val;
                }
                for (auto* neighbor : graph[node]) {
                    if (!visited.contains(neighbor)) {
                        queue.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return -1;
    }
};
