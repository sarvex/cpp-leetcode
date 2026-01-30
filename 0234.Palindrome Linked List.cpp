/**
 * @brief Two-pointer with list reversal for palindrome check
 * @intuition Find middle, reverse second half, compare both halves
 * @approach Use slow/fast pointers to find middle, reverse in-place
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto isPalindrome(ListNode* head) -> bool {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    
    auto* slow = head;
    auto* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* prev = nullptr;
    auto* current = slow->next;
    while (current != nullptr) {
      auto* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    
    auto* left = head;
    auto* right = prev;
    while (right != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }
    return true;
  }
};
