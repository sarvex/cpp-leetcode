/**
 * @brief Remove the N-th node from the end using two-pointer technique
 * @intuition Use a fast pointer to get a gap of n nodes ahead
 * @approach Introduce a dummy node, advance fast n+1 steps, then move both
 * @complexity Time: O(L), Space: O(1)
 */

#include <memory>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution final {
public:
  [[nodiscard]] auto removeNthFromEnd(ListNode* head, int n) -> ListNode* {
    auto dummy = std::make_unique<ListNode>(0, head);
    auto* fast = dummy.get();
    auto* slow = dummy.get();

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

    return dummy->next;
  }
};
