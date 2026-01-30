/**
 * @brief Count valid triangle triplets
 * @intuition Sort array and use binary search to find valid third sides
 * @approach For each pair (i,j), binary search for largest k where nums[i]+nums[j] > nums[k]
 * @complexity Time: O(n^2 log n), Space: O(log n) for sorting
 */
class Solution final {
public:
    [[nodiscard]] static int triangleNumber(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0;
        const int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                const int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                ans += k - j;
            }
        }
        return ans;
    }
};
