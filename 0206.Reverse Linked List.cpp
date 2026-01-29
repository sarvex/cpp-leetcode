/**
 * @brief Iterative linked list reversal using head insertion
 * @intuition Build reversed list by inserting each node at the front
 * @approach Use dummy head and insert each node after it
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto reverseList(ListNode* head) -> ListNode* {
        ListNode dummy;
        auto* current = head;
        
        while (current != nullptr) {
            auto* next = current->next;
            current->next = dummy.next;
            dummy.next = current;
            current = next;
        }
        
        return dummy.next;
    }
};
