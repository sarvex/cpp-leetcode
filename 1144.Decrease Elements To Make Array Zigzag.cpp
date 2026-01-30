/**
 * @brief Find minimum decreases to make array zigzag (alternating peaks and valleys)
 * @intuition Try two patterns: even indices as valleys or odd indices as valleys
 * @approach For each pattern, compute how much each valley must decrease to be strictly
 *           less than both neighbors. Return minimum of both patterns.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int movesToMakeZigzag(const vector<int>& nums) {
        vector<int> ans(2);
        const int n = nums.size();
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j) d = max(d, nums[j] - nums[j - 1] + 1);
                if (j < n - 1) d = max(d, nums[j] - nums[j + 1] + 1);
                ans[i] += d;
            }
        }
        return min(ans[0], ans[1]);
    }
};
