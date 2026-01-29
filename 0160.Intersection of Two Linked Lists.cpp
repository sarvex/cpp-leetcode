/**
 * @brief Find intersection node using two-pointer technique
 * @intuition Both pointers traverse combined length, meeting at intersection
 * @approach When one reaches end, redirect to other list's head; they'll meet at intersection
 * @complexity Time: O(m+n), Space: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto getIntersectionNode(ListNode* headA, ListNode* headB) const -> ListNode* {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        while (ptrA != ptrB) {
            ptrA = ptrA != nullptr ? ptrA->next : headB;
            ptrB = ptrB != nullptr ? ptrB->next : headA;
        }
        
        return ptrA;
    }
};
