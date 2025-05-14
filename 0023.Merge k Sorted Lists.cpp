#include <queue>
#include <vector>

struct ListNode final {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution final {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> pq;
    for (auto head : lists) {
      if (head) {
        pq.push(head);
      }
    }
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();
      if (node->next) {
        pq.push(node->next);
      }
      cur->next = node;
      cur = cur->next;
    }
    return dummy->next;
  }
};
