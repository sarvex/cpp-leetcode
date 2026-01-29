/**
 * @brief Swap every two adjacent nodes in a linked list
 * @intuition Recursively swap pairs and connect to the rest
 * @approach Swap first two nodes, recursively process rest, and link
 * @complexity Time: O(n), Space: O(n) for recursion stack
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
  [[nodiscard]] auto swapPairs(ListNode* head) -> ListNode* {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    auto* rest = swapPairs(head->next->next);
    auto* newHead = head->next;
    newHead->next = head;
    head->next = rest;

    return newHead;
  }
};
