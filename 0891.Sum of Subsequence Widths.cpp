/**
 * @brief Count each element's contribution as min/max in subsequences
 * @intuition Element at index i (sorted) is max in 2^i subsequences, min in 2^(n-1-i)
 * @approach Sort array. For each element, add its contribution: appears as max in
 *           2^i subsequences (positive) and as min in 2^(n-1-i) subsequences (negative).
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto sumSubseqWidths(std::vector<int>& nums) -> int {
        constexpr int mod = 1'000'000'007;
        std::ranges::sort(nums);
        
        long long ans = 0, p = 1;
        const int n = static_cast<int>(nums.size());
        
        for (int i = 0; i < n; ++i) {
            ans = (ans + (nums[i] - nums[n - i - 1]) * p % mod + mod) % mod;
            p = (p << 1) % mod;
        }
        return static_cast<int>(ans);
    }
};
