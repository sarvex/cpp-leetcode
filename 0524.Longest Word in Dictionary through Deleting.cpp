/**
 * @brief Find longest dictionary word that is subsequence of input string
 * @intuition Check each dictionary word if it's a subsequence; prefer longer or lexicographically smaller
 * @approach For each dictionary word, verify subsequence relationship with two pointers.
 *           Update answer if current word is longer or same length but lexicographically smaller.
 * @complexity Time: O(n * L) where n = dictionary size, L = string length
 */
class Solution final {
public:
    [[nodiscard]] static auto findLongestWord(const string& s, 
                                               const vector<string>& dictionary) -> string {
        auto isSubseq = [&s](const string& t) {
            size_t i = 0;
            for (size_t j = 0; i < t.size() && j < s.size(); ++j) {
                if (t[i] == s[j]) ++i;
            }
            return i == t.size();
        };
        
        string ans;
        for (const auto& word : dictionary) {
            const auto a = ans.size(), b = word.size();
            if (isSubseq(word) && (a < b || (a == b && ans > word))) {
                ans = word;
            }
        }
        return ans;
    }
};
