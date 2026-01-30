/**
 * @brief Dynamic programming for minimum race car instructions
 * @intuition Optimal paths involve accelerating to overshoot/undershoot then reversing
 * @approach For each position i, find k where 2^k-1 >= i. If exact match, answer is k.
 *           Otherwise, try: (1) overshoot and reverse, (2) undershoot, reverse,
 *           accelerate backwards for j steps, reverse again.
 * @complexity Time: O(target * log(target)), Space: O(target)
 */
class Solution final {
public:
    [[nodiscard]] static auto racecar(int target) -> int {
        std::vector<int> dp(target + 1);
        
        for (int i = 1; i <= target; ++i) {
            const int k = 32 - __builtin_clz(i);
            
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            
            for (int j = 0; j < k; ++j) {
                const int undershoot = i - (1 << (k - 1)) + (1 << j);
                dp[i] = std::min(dp[i], dp[undershoot] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
};
