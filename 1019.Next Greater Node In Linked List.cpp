/**
 * @brief Monotonic stack for next greater element
 * @intuition Convert to array then use decreasing stack from right
 * @approach Extract values to array, iterate backwards maintaining decreasing stack
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }
        stack<int> stk;
        const int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};
