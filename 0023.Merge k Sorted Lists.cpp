/**
 * @brief Merge k sorted linked lists using a min-heap
 * @intuition Always pick the smallest head among all lists
 * @approach Use a priority queue to efficiently get minimum element
 * @complexity Time: O(N log k), Space: O(k) where N is total nodes
 */

#include <queue>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto mergeKLists(std::vector<ListNode*>& lists)
      -> ListNode* {
    auto cmp = [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;
    };

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(
        cmp);

    for (auto* head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    ListNode dummy;
    auto* current = &dummy;

    while (!pq.empty()) {
      auto* node = pq.top();
      pq.pop();

      if (node->next != nullptr) {
        pq.push(node->next);
      }

      current->next = node;
      current = current->next;
    }

    return dummy.next;
  }
};
