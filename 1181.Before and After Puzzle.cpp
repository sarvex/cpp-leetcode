/**
 * @brief Combine phrases where last word of one matches first word of another
 * @intuition Extract first and last words, match last of i with first of j
 * @approach Parse first and last words of each phrase. For all pairs where phrase[i]'s
 *           last word equals phrase[j]'s first word, combine and collect unique results.
 * @complexity Time: O(n^2 * L) where L is average phrase length, Space: O(n * L)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> beforeAndAfterPuzzles(const vector<string>& phrases) {
        const int n = phrases.size();
        vector<pair<string, string>> ps(n);
        for (int i = 0; i < n; ++i) {
            size_t j = phrases[i].find(' ');
            if (j == string::npos) {
                ps[i] = {phrases[i], phrases[i]};
            } else {
                size_t k = phrases[i].rfind(' ');
                ps[i] = {phrases[i].substr(0, j), phrases[i].substr(k + 1)};
            }
        }
        unordered_set<string> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && ps[i].second == ps[j].first) {
                    s.insert(phrases[i] + phrases[j].substr(ps[i].second.size()));
                }
            }
        }
        vector<string> ans(s.begin(), s.end());
        ranges::sort(ans);
        return ans;
    }
};
