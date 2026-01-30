/**
 * @brief Count words where f(word) > f(query) using frequency of smallest character
 * @intuition Precompute f() for all words, sort, and use binary search for each query
 * @approach Define f(s) as count of smallest character. Compute f() for all words, sort.
 *           For each query, binary search to count words with strictly greater f() value.
 * @complexity Time: O((n + m) * L + n log n + m log n) where L is max string length, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> numSmallerByFrequency(const vector<string>& queries,
                                                           const vector<string>& words) {
        auto f = [](const string& s) {
            int cnt[26] = {0};
            for (char c : s) {
                cnt[c - 'a']++;
            }
            for (int x : cnt) {
                if (x) {
                    return x;
                }
            }
            return 0;
        };
        const int n = words.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = f(words[i]);
        }
        ranges::sort(nums);
        vector<int> ans;
        for (const auto& q : queries) {
            int x = f(q);
            ans.push_back(n - (upper_bound(nums.begin(), nums.end(), x) - nums.begin()));
        }
        return ans;
    }
};
