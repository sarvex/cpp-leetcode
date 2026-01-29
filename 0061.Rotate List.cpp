/**
 * @brief Rotate a linked list to the right by k places
 * @intuition Find the new tail (n - k % n nodes from head) and reconnect
 * @approach Count length, find split point using fast/slow pointers, reconnect
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto rotateRight(ListNode* head, int k) -> ListNode* {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    int n = 0;
    for (auto* cur = head; cur != nullptr; cur = cur->next) {
      ++n;
    }

    k %= n;
    if (k == 0) {
      return head;
    }

    auto* fast = head;
    auto* slow = head;

    for (int i = 0; i < k; ++i) {
      fast = fast->next;
    }

    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    auto* newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;

    return newHead;
  }
};
