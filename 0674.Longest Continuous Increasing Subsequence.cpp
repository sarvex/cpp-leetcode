/**
 * @brief Find length of longest continuous increasing subsequence
 * @intuition Track current streak length, reset when not increasing
 * @approach Single pass counting consecutive increases
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int findLengthOfLCIS(const vector<int>& nums) {
        int ans = 1;
        for (size_t i = 1, cnt = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
