/**
 * @brief Digit-wise addition of two reversed linked-list numbers
 * @intuition Each node represents a digit; add corresponding digits and carry
 * @approach Iterate both lists, summing digits and carry, appending new nodes
 * @complexity Time: O(max(N, M)), Space: O(max(N, M))
 */

class Solution final {
public:
  [[nodiscard]] static auto addTwoNumbers(const ListNode* l1,
                                          const ListNode* l2) -> ListNode* {
    ListNode dummy;
    auto* current = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      const int digit1 = l1 != nullptr ? l1->val : 0;
      const int digit2 = l2 != nullptr ? l2->val : 0;
      const int sum = digit1 + digit2 + carry;
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      l1 = l1 != nullptr ? l1->next : nullptr;
      l2 = l2 != nullptr ? l2->next : nullptr;
    }

    return dummy.next;
  }
};
