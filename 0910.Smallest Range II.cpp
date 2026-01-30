/**
 * @brief Minimize range by adding +k or -k to each element
 * @intuition Sort array; split into prefix (+k) and suffix (-k) groups
 * @approach Try each split point; new range is max of boundaries
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int smallestRangeII(vector<int>& nums, const int k) {
        ranges::sort(nums);
        const int n = static_cast<int>(nums.size());
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; ++i) {
            const int mi = min(nums[0] + k, nums[i] - k);
            const int mx = max(nums[i - 1] + k, nums[n - 1] - k);
            ans = min(ans, mx - mi);
        }
        return ans;
    }
};
