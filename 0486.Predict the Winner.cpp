/**
 * @brief Determine if player 1 can win or tie in optimal play
 * @intuition Minimax: maximize own score minus opponent's best response
 * @approach DP with memoization: f[i][j] = best score difference for subarray
 * @complexity Time: O(n^2), Space: O(n^2)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto predictTheWinner(const std::vector<int>& nums) const -> bool {
        const int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));

        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i > j) {
                return 0;
            }
            if (f[i][j] != 0) {
                return f[i][j];
            }
            return f[i][j] = std::max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1));
        };

        return dfs(0, n - 1) >= 0;
    }
};
