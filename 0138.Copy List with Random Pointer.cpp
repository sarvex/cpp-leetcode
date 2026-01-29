/**
 * @brief Deep copy linked list with random pointers using hash map
 * @intuition Map original nodes to copies, then wire up next and random pointers
 * @approach First pass creates copies, second pass connects random pointers
 * @complexity Time: O(n), Space: O(n)
 */

#include <unordered_map>

using std::unordered_map;

class Solution final {
public:
    [[nodiscard]] static auto copyRandomList(Node* head) -> Node* {
        auto* dummy = new Node(0);
        Node* tail = dummy;
        unordered_map<Node*, Node*> nodeMap;

        // First pass: create all nodes and build map
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            auto* copy = new Node(curr->val);
            tail->next = copy;
            tail = copy;
            nodeMap[curr] = copy;
        }

        // Second pass: connect random pointers
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            nodeMap[curr]->random = curr->random ? nodeMap[curr->random] : nullptr;
        }

        return dummy->next;
    }
};
