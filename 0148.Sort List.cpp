/**
 * @brief Sort linked list using merge sort
 * @intuition Merge sort is optimal for linked lists due to O(1) merge
 * @approach Split at middle using slow/fast pointers, recursively sort and merge
 * @complexity Time: O(n log n), Space: O(log n) for recursion stack
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto sortList(ListNode* head) const -> ListNode* {
        if (!head || !head->next) {
            return head;
        }
        
        // Find middle using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list
        ListNode* rightHead = slow->next;
        slow->next = nullptr;
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        
        // Merge sorted halves
        auto* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        tail->next = left != nullptr ? left : right;
        return dummy->next;
    }
};
