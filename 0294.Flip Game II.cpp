/**
 * @brief Game theory with memoization for flip game
 * @intuition Use bitmask to represent state, memoize results
 * @approach DFS: win if any move leads to opponent losing
 * @complexity Time: O(2^n), Space: O(2^n)
 */
class Solution final {
public:
    [[nodiscard]] bool canWin(const string& currentState) {
        n_ = static_cast<int>(currentState.size());
        long long mask = 0;
        for (int i = 0; i < n_; ++i) {
            if (currentState[i] == '+') {
                mask |= 1LL << i;
            }
        }
        return dfs(mask);
    }

private:
    int n_ = 0;
    unordered_map<long long, bool> memo_;

    [[nodiscard]] bool dfs(long long mask) {
        if (memo_.contains(mask)) {
            return memo_[mask];
        }
        for (int i = 0; i < n_ - 1; ++i) {
            if ((mask & (1LL << i)) == 0 || (mask & (1LL << (i + 1))) == 0) {
                continue;
            }
            if (!dfs(mask ^ (1LL << i) ^ (1LL << (i + 1)))) {
                memo_[mask] = true;
                return true;
            }
        }
        memo_[mask] = false;
        return false;
    }
};
