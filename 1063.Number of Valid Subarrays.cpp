/**
 * @brief Monotonic stack for counting valid subarrays
 * @intuition Valid subarray starts at i until first smaller element
 * @approach Use stack to find next smaller element for each position
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int validSubarrays(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += right[i] - i;
        }
        return ans;
    }
};
