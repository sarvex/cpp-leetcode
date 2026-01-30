/**
 * @brief Delete and earn points using house robber DP
 * @intuition Choosing number x removes all x-1 and x+1; similar to house robber
 * @approach Transform to value array, apply house robber algorithm
 * @complexity Time: O(n + max_val), Space: O(max_val)
 */
class Solution final {
public:
    [[nodiscard]] static int deleteAndEarn(const std::vector<int>& nums) {
        std::array<int, 10010> values{};
        for (const int num : nums) {
            values[num] += num;
        }
        
        int prev2 = 0;
        int prev1 = values[0];
        for (int i = 1; i < 10010; ++i) {
            const int curr = std::max(values[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
