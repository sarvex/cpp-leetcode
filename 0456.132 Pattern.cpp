/**
 * @brief Find if array has 132 pattern (i<j<k, nums[i]<nums[k]<nums[j])
 * @intuition Track potential '2' (k value) using decreasing monotonic stack
 * @approach Scan right to left, maintain max potential k value
 * @complexity Time: O(n) Space: O(n)
 */
#include <climits>
#include <stack>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto find132pattern(const std::vector<int>& nums) const -> bool {
        int vk = INT_MIN;
        std::stack<int> stk;

        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            if (nums[i] < vk) {
                return true;
            }
            while (!stk.empty() && stk.top() < nums[i]) {
                vk = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }

        return false;
    }
};
