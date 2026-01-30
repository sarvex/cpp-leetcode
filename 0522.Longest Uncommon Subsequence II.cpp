/**
 * @brief Find longest uncommon subsequence among array of strings
 * @intuition A string is uncommon if it's not a subsequence of any other string
 * @approach For each string, check if it's a subsequence of any other string.
 *           If not, it's a candidate. Track maximum length among valid candidates.
 * @complexity Time: O(n^2 * L), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto findLUSlength(const vector<string>& strs) -> int {
        const int n = static_cast<int>(strs.size());
        
        auto isSubseq = [](const string& s, const string& t) {
            size_t i = 0;
            for (size_t j = 0; i < s.size() && j < t.size(); ++j) {
                if (s[i] == t[j]) ++i;
            }
            return i == s.size();
        };
        
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int len = static_cast<int>(strs[i].size());
            bool isUncommon = true;
            
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubseq(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            
            if (isUncommon) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
