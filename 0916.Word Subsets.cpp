/**
 * @brief Find universal words containing all subset requirements
 * @intuition Merge all subset requirements, check each word against merged
 * @approach Compute max frequency needed for each char from words2, filter words1
 * @complexity Time: O(A + B), Space: O(26) where A, B are total chars
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> wordSubsets(const vector<string>& words1, const vector<string>& words2) {
        int cnt[26] = {0};
        int t[26];
        for (const auto& b : words2) {
            memset(t, 0, sizeof t);
            for (const char c : b) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = max(cnt[i], t[i]);
            }
        }
        vector<string> ans;
        for (const auto& a : words1) {
            memset(t, 0, sizeof t);
            for (const char c : a) {
                t[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(a);
            }
        }
        return ans;
    }
};
