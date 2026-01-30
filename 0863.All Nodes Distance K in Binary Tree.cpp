/**
 * @brief Build parent pointers then BFS/DFS from target node
 * @intuition Convert tree to graph by adding parent references; find nodes at distance k
 * @approach First DFS to build parent map. Then DFS from target, exploring children
 *           and parent, counting distance. Collect nodes at exactly distance k.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] auto distanceK(TreeNode* root, TreeNode* target, int k)
        -> std::vector<int> {
        std::unordered_map<TreeNode*, TreeNode*> parent;
        std::vector<int> ans;

        auto buildParent = [&](auto&& self, TreeNode* node, TreeNode* fa) -> void {
            if (!node) return;
            parent[node] = fa;
            self(self, node->left, node);
            self(self, node->right, node);
        };

        auto findNodes = [&](auto&& self, TreeNode* node, TreeNode* fa, int dist) -> void {
            if (!node) return;
            if (dist == 0) {
                ans.push_back(node->val);
                return;
            }
            for (auto* nxt : {node->left, node->right, parent[node]}) {
                if (nxt != fa) {
                    self(self, nxt, node, dist - 1);
                }
            }
        };

        buildParent(buildParent, root, nullptr);
        findNodes(findNodes, target, nullptr, k);
        return ans;
    }
};
