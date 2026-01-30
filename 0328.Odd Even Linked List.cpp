/**
 * @brief Group odd and even indexed nodes in linked list
 * @intuition Maintain two lists for odd and even nodes, then connect
 * @approach Use two pointers to separate odd/even, then link them
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
