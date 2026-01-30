/**
 * @brief Two-pointer technique to find middle node
 * @intuition Slow pointer moves 1 step, fast moves 2; when fast reaches end, slow is at middle
 * @approach Initialize slow and fast at head. Move slow by 1 and fast by 2 until
 *           fast reaches end. Slow points to middle (second middle if even length).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto middleNode(ListNode* head) -> ListNode* {
        auto* slow = head;
        auto* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
