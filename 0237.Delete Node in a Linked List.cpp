/**
 * @brief Delete node by copying next node's data
 * @intuition Copy next node's value into current, then skip next node
 * @approach Overwrite current node with next node's data
 * @complexity Time: O(1), Space: O(1)
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution final {
public:
  auto deleteNode(ListNode* node) const -> void {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
