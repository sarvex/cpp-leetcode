/**
 * @brief Reverse nodes in k-group segments
 * @intuition Reverse each complete group of k nodes
 * @approach Count k nodes, reverse them, and connect to recursively processed rest
 * @complexity Time: O(n), Space: O(1)
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
  [[nodiscard]] auto reverseKGroup(ListNode* head, int k) -> ListNode* {
    auto dummy = std::make_unique<ListNode>(0, head);
    auto* pre = dummy.get();

    while (pre != nullptr) {
      auto* cur = pre;
      for (int i = 0; i < k; ++i) {
        cur = cur->next;
        if (cur == nullptr) {
          return dummy->next;
        }
      }

      auto* node = pre->next;
      auto* nxt = cur->next;
      cur->next = nullptr;
      pre->next = reverse(node);
      node->next = nxt;
      pre = node;
    }

    return dummy->next;
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
