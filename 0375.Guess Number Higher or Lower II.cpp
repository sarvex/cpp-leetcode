/**
 * @brief Find minimum money to guarantee winning the number guessing game
 * @intuition Minimax: minimize the worst-case cost across all possible guesses
 * @approach DP where f[i][j] = min cost to guess answer in range [i,j]
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto getMoneyAmount(int n) -> int {
        std::vector<std::vector<int>> f(n + 2, std::vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; ++k) {
                    f[i][j] = std::min(f[i][j], std::max(f[i][k - 1], f[k + 1][j]) + k);
                }
            }
        }

        return f[1][n];
    }
};
