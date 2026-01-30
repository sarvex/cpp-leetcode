/**
 * @brief Monotonic stack with circular array traversal
 * @intuition Circular array means we need to look beyond the end; simulated by iterating twice
 * @approach Traverse array twice (2n iterations) using monotonic decreasing stack.
 *           Stack stores values; when current element is larger, it's the next greater for stack top.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto nextGreaterElements(const vector<int>& nums) -> vector<int> {
        const int n = static_cast<int>(nums.size());
        vector<int> ans(n, -1);
        stack<int> stk;
        
        for (int i = n * 2 - 1; i >= 0; --i) {
            const int j = i % n;
            while (!stk.empty() && stk.top() <= nums[j]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[j] = stk.top();
            }
            stk.push(nums[j]);
        }
        return ans;
    }
};
