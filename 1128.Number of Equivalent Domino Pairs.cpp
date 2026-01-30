/**
 * @brief Count pairs of dominoes that are equivalent (same values regardless of orientation)
 * @intuition Normalize dominoes by putting smaller value first, then count matching pairs
 * @approach For each domino, create normalized key (smaller*10 + larger). For each new domino
 *           with same key, it forms pairs with all previously seen identical dominoes.
 * @complexity Time: O(n), Space: O(1) - at most 100 distinct normalized values
 */
class Solution final {
public:
    [[nodiscard]] static int numEquivDominoPairs(const vector<vector<int>>& dominoes) {
        int cnt[100]{};
        int ans = 0;
        for (const auto& e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
};
