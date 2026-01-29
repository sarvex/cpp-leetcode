/**
 * @brief Remove nodes with target value using dummy head
 * @intuition Use a dummy node to handle edge cases uniformly
 * @approach Iterate through list, skip nodes with matching value
 * @complexity Time: O(n), Space: O(1)
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution final {
public:
  [[nodiscard]] auto removeElements(ListNode* head, int val) const -> ListNode* {
    auto dummy = ListNode();
    dummy.next = head;
    auto* current = &dummy;
    while (current->next != nullptr) {
      if (current->next->val == val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }
    return dummy.next;
  }
};
