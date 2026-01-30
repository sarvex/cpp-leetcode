/**
 * @brief Find longest substring of same character achievable with one swap
 * @intuition Consider joining two segments separated by one different character using a swap
 * @approach Track character counts and iterate through runs. For each run, try extending by
 *           joining with next same-character run (separated by one char) if spare chars exist.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxRepOpt1(const string& text) {
        int cnt[26] = {0};
        for (char c : text) {
            ++cnt[c - 'a'];
        }
        const int n = text.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) {
                ++j;
            }
            int l = j - i;
            int k = j + 1;
            while (k < n && text[k] == text[i]) {
                ++k;
            }
            int r = k - j - 1;
            ans = max(ans, min(l + r + 1, cnt[text[i] - 'a']));
            i = j;
        }
        return ans;
    }
};
