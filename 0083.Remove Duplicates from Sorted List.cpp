/**
 * @brief In-place deletion of duplicates in a sorted linked list
 * @intuition Since list is sorted, duplicates are adjacent; skip them
 * @approach Traverse list comparing current with next; skip duplicates by adjusting pointers
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto deleteDuplicates(ListNode* head) -> ListNode* {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
