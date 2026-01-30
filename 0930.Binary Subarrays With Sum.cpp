/**
 * @brief Count subarrays with given sum using prefix sum
 * @intuition Use hash map to count prefix sums; lookup complement
 * @approach For each position, add count of prefix sums equal to (current - goal)
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int numSubarraysWithSum(const vector<int>& nums, const int goal) {
        const int n = static_cast<int>(nums.size());
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        int ans = 0, s = 0;
        for (const int v : nums) {
            s += v;
            if (s - goal >= 0) {
                ans += cnt[s - goal];
            }
            ++cnt[s];
        }
        return ans;
    }
};
