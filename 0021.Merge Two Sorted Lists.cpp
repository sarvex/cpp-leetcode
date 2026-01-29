/**
 * @brief Merge two sorted linked lists recursively
 * @intuition Compare heads and recursively merge the rest
 * @approach Pick smaller head, attach merged result of remaining lists
 * @complexity Time: O(n + m), Space: O(n + m) for recursion stack
 */

class Solution final {
public:
  [[nodiscard]] static auto mergeTwoLists(ListNode* list1, ListNode* list2)
      -> ListNode* {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }

    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};
