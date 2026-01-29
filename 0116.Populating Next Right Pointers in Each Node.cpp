/**
 * @brief Connect nodes at same level using BFS
 * @intuition Level order traversal connecting adjacent nodes in queue
 * @approach Use queue to process level by level, link consecutive nodes
 * @complexity Time: O(n), Space: O(w) where w is max width
 */

class Solution final {
public:
    [[nodiscard]] static auto connect(Node* root) -> Node* {
        if (!root) {
            return root;
        }
        
        std::queue<Node*> q{{root}};
        while (!q.empty()) {
            Node* prev = nullptr;
            for (int n = q.size(); n > 0; --n) {
                Node* node = q.front();
                q.pop();
                if (prev != nullptr) {
                    prev->next = node;
                }
                prev = node;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
