/**
 * @brief Reverse linked list nodes between positions left and right
 * @intuition Isolate the sublist to reverse, then reconnect
 * @approach Find node before left, reverse sublist, reconnect ends
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto reverseBetween(ListNode* head, const int left, const int right) -> ListNode* {
        if (head->next == nullptr || left == right) {
            return head;
        }
        
        auto dummy = new ListNode(0, head);
        auto prev = dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        auto beforeReverse = prev;
        auto reverseEnd = prev->next;
        auto curr = reverseEnd;
        
        for (int i = 0; i < right - left + 1; ++i) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        beforeReverse->next = prev;
        reverseEnd->next = curr;
        
        return dummy->next;
    }
};
