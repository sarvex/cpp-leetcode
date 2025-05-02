#include <memory>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Digit-wise addition of two reversed linked-list numbers.
 * @intuition: Each node represents a digit; add corresponding digits and carry,
 * as in grade-school addition.
 * @approach: Iterate both lists, summing digits and carry, appending new nodes
 * to result. Use a dummy head for simplicity.
 * @complexity: O(max(N, M)) time, O(max(N, M)) space.
 */
class Solution {
public:
  /**
   * Adds two numbers represented by reversed linked lists.
   * @param l1 First number as a linked list (least significant digit first).
   * @param l2 Second number as a linked list (least significant digit first).
   * @return Head of new linked list representing the sum.
   */
  [[nodiscard]] static auto addTwoNumbers(const ListNode *l1,
                                          const ListNode *l2) -> ListNode * {
    auto dummy = std::make_unique<ListNode>();
    auto current = dummy.get();
    int carry = 0;
    while (l1 || l2 || carry) {
      const int digit1 = l1 ? l1->val : 0;
      const int digit2 = l2 ? l2->val : 0;
      const int sum = digit1 + digit2 + carry;
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return dummy->next;
  }
};
