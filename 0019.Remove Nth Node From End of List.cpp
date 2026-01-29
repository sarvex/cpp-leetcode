/**
 * @brief Remove the N-th node from the end using two-pointer technique
 * @intuition Use a fast pointer to get a gap of n nodes ahead
 * @approach Introduce a dummy node, advance fast n+1 steps, then move both
 * @complexity Time: O(L), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto removeNthFromEnd(ListNode* head, const int n)
      -> ListNode* {
    ListNode dummy(0, head);
    auto* fast = &dummy;
    auto* slow = &dummy;

    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }

    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    auto* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy.next;
  }
};
