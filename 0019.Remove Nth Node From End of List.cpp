#include <memory>

struct ListNode final {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution final {
public:
  /**
   * @brief Remove the N-th node from the end of a singly-linked list using
   * two-pointer technique.
   * @intuition: Use a fast pointer to get a gap of n nodes ahead, then move
   * both pointers until fast reaches the end.
   * @approach: Introduce a dummy node to handle edge cases, advance fast
   * pointer n+1 steps, then move both pointers until fast is null. Remove the
   * target node and return the new head.
   * @complexity: Time O(L), where L is the length of the list.
   * @complexity: Space O(1), constant extra space.
   */
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = std::make_unique<ListNode>(0, head);
    auto fast = dummy.get();
    auto slow = dummy.get();
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    auto toDelete = slow->next;
    slow->next = slow->next->next;
    // No need to delete toDelete explicitly if using smart pointers in full
    // impl
    return dummy->next;
  }
};
