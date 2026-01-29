/**
 * @brief Determine if first player can win choosing numbers 1 to maxChoosable
 * @intuition Game theory with memoization on used numbers bitmask
 * @approach DFS trying each unused number, win if opponent can't win from resulting state
 * @complexity Time: O(2^n * n) Space: O(2^n)
 */
#include <functional>
#include <unordered_map>

class Solution final {
public:
    [[nodiscard]] auto canIWin(int maxChoosableInteger, int desiredTotal) const -> bool {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }

        std::unordered_map<int, int> f;

        std::function<bool(int, int)> dfs = [&](int mask, int s) -> bool {
            if (f.contains(mask)) {
                return f[mask];
            }
            for (int i = 0; i < maxChoosableInteger; ++i) {
                if (((mask >> i) & 1) ^ 1) {
                    if (s + i + 1 >= desiredTotal || !dfs(mask | (1 << i), s + i + 1)) {
                        return f[mask] = true;
                    }
                }
            }
            return f[mask] = false;
        };

        return dfs(0, 0);
    }
};
