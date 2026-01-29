/**
 * @brief Partition linked list around value x
 * @intuition Separate nodes into two lists: less than x and >= x
 * @approach Build two separate lists using dummy heads, then concatenate
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto partition(ListNode* head, const int x) -> ListNode* {
        ListNode leftDummy;
        ListNode rightDummy;
        auto leftTail = &leftDummy;
        auto rightTail = &rightDummy;
        
        for (; head != nullptr; head = head->next) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            } else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
        }
        
        rightTail->next = nullptr;
        leftTail->next = rightDummy.next;
        return leftDummy.next;
    }
};
