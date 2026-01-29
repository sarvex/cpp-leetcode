/**
 * @brief Detect cycle in linked list using Floyd's algorithm
 * @intuition Fast pointer moves twice as fast; if there's a cycle, they will meet
 * @approach Use slow and fast pointers; return true if they meet
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto hasCycle(ListNode* head) -> bool {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
