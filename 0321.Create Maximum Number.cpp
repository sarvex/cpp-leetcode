/**
 * @brief Create maximum number from two arrays with k digits
 * @intuition Try all ways to split k between two arrays, merge optimally
 * @approach Use monotonic stack to get max subsequence, then merge greedily
 * @complexity Time: O(k^2 * (m + n)), Space: O(k)
 */
#include <algorithm>
#include <functional>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<int> maxNumber(std::vector<int>& nums1, 
                                              std::vector<int>& nums2, int k) const {
        auto getMax = [](std::vector<int>& nums, int len) -> std::vector<int> {
            const int n = static_cast<int>(nums.size());
            std::vector<int> stk(len);
            int top = -1;
            int remain = n - len;
            
            for (const int x : nums) {
                while (top >= 0 && stk[top] < x && remain > 0) {
                    --top;
                    --remain;
                }
                if (top + 1 < len) {
                    stk[++top] = x;
                } else {
                    --remain;
                }
            }
            return stk;
        };
        
        std::function<bool(std::vector<int>&, std::vector<int>&, int, int)> compare;
        compare = [&](std::vector<int>& a, std::vector<int>& b, int i, int j) -> bool {
            if (i >= static_cast<int>(a.size())) {
                return false;
            }
            if (j >= static_cast<int>(b.size())) {
                return true;
            }
            if (a[i] > b[j]) {
                return true;
            }
            if (a[i] < b[j]) {
                return false;
            }
            return compare(a, b, i + 1, j + 1);
        };

        auto merge = [&](std::vector<int>& a, std::vector<int>& b) -> std::vector<int> {
            const int m = static_cast<int>(a.size());
            const int n = static_cast<int>(b.size());
            int i = 0;
            int j = 0;
            std::vector<int> result(m + n);
            
            for (int idx = 0; idx < m + n; ++idx) {
                if (compare(a, b, i, j)) {
                    result[idx] = a[i++];
                } else {
                    result[idx] = b[j++];
                }
            }
            return result;
        };

        const int m = static_cast<int>(nums1.size());
        const int n = static_cast<int>(nums2.size());
        const int left = std::max(0, k - n);
        const int right = std::min(k, m);
        std::vector<int> ans(k);
        
        for (int x = left; x <= right; ++x) {
            std::vector<int> arr1 = getMax(nums1, x);
            std::vector<int> arr2 = getMax(nums2, k - x);
            std::vector<int> arr = merge(arr1, arr2);
            if (ans < arr) {
                ans = std::move(arr);
            }
        }
        return ans;
    }
};
