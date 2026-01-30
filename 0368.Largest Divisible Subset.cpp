/**
 * @brief Find largest subset where every pair is divisible
 * @intuition Sort and use DP, if a divides b and b divides c, then a divides c
 * @approach DP tracking longest chain ending at each element, reconstruct path
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        std::ranges::sort(nums);
        const int n = static_cast<int>(nums.size());
        std::vector<int> f(n, 1);
        int k = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = std::max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        
        int m = f[k];
        std::vector<int> ans;
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.push_back(nums[i]);
                k = i;
                --m;
            }
        }
        return ans;
    }
};
