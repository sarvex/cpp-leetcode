/**
 * @brief Reverse nodes in k-group segments
 * @intuition Reverse each complete group of k nodes
 * @approach Count k nodes, reverse them, and connect to recursively processed rest
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto reverseKGroup(ListNode* head, const int k)
      -> ListNode* {
    ListNode dummy(0, head);
    auto* pre = &dummy;

    while (pre != nullptr) {
      auto* cur = pre;
      for (int i = 0; i < k; ++i) {
        cur = cur->next;
        if (cur == nullptr) {
          return dummy.next;
        }
      }

      auto* node = pre->next;
      auto* nxt = cur->next;
      cur->next = nullptr;
      pre->next = reverse(node);
      node->next = nxt;
      pre = node;
    }

    return dummy.next;
  }

private:
  [[nodiscard]] static auto reverse(ListNode* head) -> ListNode* {
    ListNode* prev = nullptr;
    auto* cur = head;

    while (cur != nullptr) {
      auto* nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    return prev;
  }
};
