/**
 * @brief Connect nodes at same level using BFS for arbitrary binary tree
 * @intuition Level order traversal connecting adjacent nodes in queue
 * @approach Use queue to process level by level, link consecutive nodes
 * @complexity Time: O(n), Space: O(w) where w is max width
 */

#include <queue>

using std::queue;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution final {
public:
    [[nodiscard]] auto connect(Node* root) -> Node* {
        if (!root) {
            return root;
        }
        
        queue<Node*> q{{root}};
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
