/**
 * @brief Add one to number represented as linked list
 * @intuition Find rightmost non-9 digit to increment, set trailing 9s to 0
 * @approach Use dummy node for carry case, find last non-9, increment and reset
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* target = dummy;
        
        for (; head != nullptr; head = head->next) {
            if (head->val != 9) {
                target = head;
            }
        }
        
        ++target->val;
        for (target = target->next; target != nullptr; target = target->next) {
            target->val = 0;
        }
        
        return dummy->val != 0 ? dummy : dummy->next;
    }
};
