/**
 * @brief Remove nodes with target value using dummy head
 * @intuition Use a dummy node to handle edge cases uniformly
 * @approach Iterate through list, skip nodes with matching value
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto removeElements(ListNode* head, int val) -> ListNode* {
        ListNode dummy;
        dummy.next = head;
        auto* current = &dummy;
        
        while (current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return dummy.next;
    }
};
