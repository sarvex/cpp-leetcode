/**
 * @brief Find length of longest wiggle subsequence (alternating increases/decreases)
 * @intuition Track separate lengths for sequences ending with up vs down move
 * @approach f[i] = max length ending with increase, g[i] = ending with decrease
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto wiggleMaxLength(const std::vector<int>& nums) -> int {
        const auto n = static_cast<int>(nums.size());
        int ans = 1;
        std::vector<int> f(n, 1);
        std::vector<int> g(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = std::max(f[i], g[j] + 1);
                } else if (nums[j] > nums[i]) {
                    g[i] = std::max(g[i], f[j] + 1);
                }
            }
            ans = std::max({ans, f[i], g[i]});
        }

        return ans;
    }
};
