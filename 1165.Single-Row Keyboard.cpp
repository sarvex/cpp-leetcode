/**
 * @brief Calculate total finger movement on single-row keyboard
 * @intuition Sum absolute differences between consecutive key positions
 * @approach Map each character to its position on keyboard. Iterate through word and
 *           accumulate distance from current position to next character.
 * @complexity Time: O(n + 26), Space: O(26)
 */
class Solution final {
public:
    [[nodiscard]] static int calculateTime(const string& keyboard, const string& word) {
        int pos[26];
        for (int i = 0; i < 26; ++i) {
            pos[keyboard[i] - 'a'] = i;
        }
        int ans = 0, i = 0;
        for (char c : word) {
            int j = pos[c - 'a'];
            ans += abs(i - j);
            i = j;
        }
        return ans;
    }
};
