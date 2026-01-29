/**
 * @brief Iterative linked list reversal using head insertion
 * @intuition Build reversed list by inserting each node at the front
 * @approach Use dummy head and insert each node after it
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
  [[nodiscard]] auto reverseList(ListNode* head) const -> ListNode* {
    ListNode dummy;
    auto* current = head;
    while (current != nullptr) {
      auto* next = current->next;
      current->next = dummy.next;
      dummy.next = current;
      current = next;
    }
    return dummy.next;
  }
};
