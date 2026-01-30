/**
 * @brief Remove consecutive sequences that sum to zero from linked list
 * @intuition Use prefix sums; if same prefix sum seen twice, nodes between sum to zero
 * @approach First pass: record last occurrence of each prefix sum. Second pass: for each
 *           prefix sum, skip ahead to the last node with same sum (removing zero-sum sequence).
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> last;
        ListNode* cur = dummy;
        int s = 0;
        while (cur) {
            s += cur->val;
            last[s] = cur;
            cur = cur->next;
        }
        s = 0;
        cur = dummy;
        while (cur) {
            s += cur->val;
            cur->next = last[s]->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
