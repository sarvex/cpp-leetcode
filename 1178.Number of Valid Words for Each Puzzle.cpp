/**
 * @brief Count words valid for each puzzle using bitmask subset enumeration
 * @intuition Word is valid if it contains puzzle's first letter and uses only puzzle letters
 * @approach Convert words to bitmasks and count. For each puzzle, enumerate all subsets of its
 *           bitmask that include the first letter, summing counts of matching word masks.
 * @complexity Time: O(W*L + P*2^7) where W is words, L is word length, P is puzzles, Space: O(2^26)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findNumOfValidWords(const vector<string>& words,
                                                         const vector<string>& puzzles) {
        unordered_map<int, int> cnt;
        for (const auto& w : words) {
            int mask = 0;
            for (char c : w) {
                mask |= 1 << (c - 'a');
            }
            cnt[mask]++;
        }
        vector<int> ans;
        for (const auto& p : puzzles) {
            int mask = 0;
            for (char c : p) {
                mask |= 1 << (c - 'a');
            }
            int x = 0;
            int i = p[0] - 'a';
            for (int j = mask; j; j = (j - 1) & mask) {
                if (j >> i & 1) {
                    x += cnt[j];
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
