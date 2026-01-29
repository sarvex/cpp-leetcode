/**
 * @brief Find cycle start node using Floyd's algorithm
 * @intuition When slow and fast meet, distance from head to cycle start equals distance from meeting point
 * @approach After detection, move one pointer from head; they meet at cycle start
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto detectCycle(ListNode* head) -> ListNode* {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }

        return nullptr;
    }
};
