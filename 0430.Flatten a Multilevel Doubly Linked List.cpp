/**
 * @brief Flatten multilevel doubly linked list depth-first
 * @intuition Insert child chain between current and next, recursively flatten
 * @approach Return tail of flattened sublist to properly link next nodes
 * @complexity Time: O(n) Space: O(d) where d is max depth
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution final {
public:
    [[nodiscard]] auto flatten(Node* head) -> Node* {
        flattenGetTail(head);
        return head;
    }

private:
    [[nodiscard]] auto flattenGetTail(Node* head) -> Node* {
        Node* cur = head;
        Node* tail = nullptr;

        while (cur) {
            Node* next = cur->next;

            if (cur->child) {
                Node* child = cur->child;
                Node* childTail = flattenGetTail(cur->child);

                cur->child = nullptr;
                cur->next = child;
                child->prev = cur;
                childTail->next = next;

                if (next) {
                    next->prev = childTail;
                }

                tail = childTail;
            } else {
                tail = cur;
            }

            cur = next;
        }

        return tail;
    }
};
