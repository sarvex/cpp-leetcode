/**
 * @brief Find next greater element for each element in nums1 from nums2
 * @intuition Monotonic decreasing stack finds next greater efficiently
 * @approach Build map of next greater from nums2, lookup for nums1
 * @complexity Time: O(m + n), Space: O(n)
 */
#include <ranges>
#include <stack>
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto nextGreaterElement(const std::vector<int>& nums1,
                                           std::vector<int>& nums2) const -> std::vector<int> {
        std::stack<int> stk;
        std::unordered_map<int, int> nextGreater;

        for (const int x : nums2 | std::views::reverse) {
            while (!stk.empty() && stk.top() < x) {
                stk.pop();
            }
            if (!stk.empty()) {
                nextGreater[x] = stk.top();
            }
            stk.push(x);
        }

        std::vector<int> ans;
        ans.reserve(nums1.size());

        for (const int x : nums1) {
            ans.push_back(nextGreater.contains(x) ? nextGreater[x] : -1);
        }

        return ans;
    }
};
