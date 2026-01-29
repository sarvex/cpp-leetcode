/**
 * @brief Return level order traversal of n-ary tree
 * @intuition BFS naturally processes nodes level by level
 * @approach Use queue, process all nodes at current level before moving to next
 * @complexity Time: O(n) Space: O(w) where w is max width
 */
#include <queue>
#include <vector>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution final {
public:
    [[nodiscard]] auto levelOrder(Node* root) const -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> ans;

        if (!root) {
            return ans;
        }

        std::queue<Node*> q{{root}};

        while (!q.empty()) {
            std::vector<int> level;

            for (int n = static_cast<int>(q.size()); n > 0; --n) {
                auto* node = q.front();
                q.pop();
                level.push_back(node->val);

                for (auto* child : node->children) {
                    q.push(child);
                }
            }

            ans.push_back(std::move(level));
        }

        return ans;
    }
};
