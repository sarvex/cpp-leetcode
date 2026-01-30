/**
 * @brief Construct array with exactly k distinct differences
 * @intuition Alternate between min and max for first k elements to create k differences
 * @approach Fill first k positions alternating low/high, rest monotonic
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> constructArray(const int n, const int k) {
        int l = 1, r = n;
        vector<int> ans(n);
        
        for (int i = 0; i < k; ++i) {
            ans[i] = i % 2 == 0 ? l++ : r--;
        }
        for (int i = k; i < n; ++i) {
            ans[i] = k % 2 == 0 ? r-- : l++;
        }
        return ans;
    }
};
