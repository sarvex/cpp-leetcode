/**
 * @brief Greedy two-pointer for maximizing token score
 * @intuition Play cheapest tokens face-up, most expensive face-down
 * @approach Sort; use two pointers to play optimal token each turn
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int bagOfTokensScore(vector<int>& tokens, int power) {
        ranges::sort(tokens);
        int ans = 0, score = 0;
        for (int i = 0, j = static_cast<int>(tokens.size()) - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = max(ans, ++score);
            } else if (score > 0) {
                power += tokens[j--];
                --score;
            } else {
                break;
            }
        }
        return ans;
    }
};
