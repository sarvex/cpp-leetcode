/**
 * @brief Remove all nodes with duplicate values from sorted linked list
 * @intuition Use dummy head and skip all nodes with duplicate values
 * @approach Track previous node; when duplicates found, skip entire group
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto deleteDuplicates(ListNode* head) -> ListNode* {
        auto dummy = new ListNode(0, head);
        auto prev = dummy;
        auto curr = head;
        
        while (curr != nullptr) {
            while (curr->next != nullptr && curr->next->val == curr->val) {
                curr = curr->next;
            }
            if (prev->next == curr) {
                prev = curr;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
