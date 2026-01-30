/**
 * @brief DP with predecessor lookup via hash map
 * @intuition Word chain forms by adding one char; sort by length, DP on predecessors
 * @approach Sort by length, for each word try all predecessors, track max chain
 * @complexity Time: O(n * L^2) where L = max word length, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int res = 0;
        unordered_map<string, int> dp;
        for (const auto& word : words) {
            int x = 1;
            for (size_t i = 0; i < word.size(); ++i) {
                const string pre = word.substr(0, i) + word.substr(i + 1);
                x = max(x, dp[pre] + 1);
            }
            dp[word] = x;
            res = max(res, x);
        }
        return res;
    }
};
