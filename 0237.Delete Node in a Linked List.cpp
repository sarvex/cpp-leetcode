/**
 * @brief Delete node by copying next node's data
 * @intuition Copy next node's value into current, then skip next node
 * @approach Overwrite current node with next node's data
 * @complexity Time: O(1), Space: O(1)
 */

class Solution final {
public:
  static auto deleteNode(ListNode* node) -> void {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
