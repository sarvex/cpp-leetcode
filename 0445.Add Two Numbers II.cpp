/**
 * @brief Add two numbers represented as linked lists (most significant digit first)
 * @intuition Use stacks to reverse order for addition
 * @approach Push digits to stacks, pop and add with carry, build result from front
 * @complexity Time: O(m + n) Space: O(m + n)
 */
#include <stack>

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
    [[nodiscard]] auto addTwoNumbers(ListNode* l1, ListNode* l2) const -> ListNode* {
        std::stack<int> s1;
        std::stack<int> s2;

        for (; l1; l1 = l1->next) {
            s1.push(l1->val);
        }
        for (; l2; l2 = l2->next) {
            s2.push(l2->val);
        }

        auto* dummy = new ListNode();
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry) {
            int s = carry;
            if (!s1.empty()) {
                s += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                s += s2.top();
                s2.pop();
            }
            dummy->next = new ListNode(s % 10, dummy->next);
            carry = s / 10;
        }

        return dummy->next;
    }
};
