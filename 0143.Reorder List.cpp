/**
 * @brief Reorder list by splitting, reversing second half, and merging
 * @intuition Split at middle, reverse second half, interleave both halves
 * @approach Find middle with slow/fast, reverse second half, merge alternately
 * @complexity Time: O(n), Space: O(1)
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
    auto reorderList(ListNode* head) -> void {
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Merge two halves
        curr = head;
        while (prev != nullptr) {
            ListNode* nextPrev = prev->next;
            prev->next = curr->next;
            curr->next = prev;
            curr = prev->next;
            prev = nextPrev;
        }
    }
};
