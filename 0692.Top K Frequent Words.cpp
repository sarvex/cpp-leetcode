/**
 * @brief Find k most frequent words, sorted by frequency then lexicographically
 * @intuition Count frequencies, sort by frequency descending and lex ascending
 * @approach Use hashmap for counting, custom sort comparator
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> topKFrequent(const vector<string>& words, const int k) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            ++cnt[w];
        }
        
        vector<string> ans;
        for (const auto& [w, _] : cnt) {
            ans.push_back(w);
        }
        
        ranges::sort(ans, [&](const string& a, const string& b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        
        ans.resize(k);
        return ans;
    }
};
