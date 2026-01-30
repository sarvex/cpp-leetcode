/**
 * @brief Sum lengths of words that can be formed using available characters
 * @intuition A word can be formed if each character's count doesn't exceed available count
 * @approach Count characters in chars. For each word, verify all character counts are within limits.
 *           Sum lengths of valid words.
 * @complexity Time: O(n + sum of word lengths), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int countCharacters(const vector<string>& words, const string& chars) {
        int cnt[26]{};
        for (char c : chars) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (const auto& w : words) {
            int wc[26]{};
            bool ok = true;
            for (char c : w) {
                int i = c - 'a';
                if (++wc[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += w.size();
            }
        }
        return ans;
    }
};
