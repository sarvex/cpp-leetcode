/**
 * @brief Count number of combinations that sum to target (order matters)
 * @intuition This is actually counting permutations, not combinations
 * @approach DP: f[i] = sum of f[i-x] for each number x <= i
 * @complexity Time: O(target * n), Space: O(target)
 */
class Solution final {
public:
    [[nodiscard]] static auto combinationSum4(const std::vector<int>& nums, int target) -> int {
        std::vector<unsigned int> f(target + 1, 0);
        f[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (const int x : nums) {
                if (i >= x) {
                    f[i] += f[i - x];
                }
            }
        }

        return static_cast<int>(f[target]);
    }
};
