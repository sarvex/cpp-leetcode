/**
 * @brief Monotonic stack for smallest lexicographic result
 * @intuition Greedily build result, removing larger chars that appear later
 * @approach Use stack and track last occurrence of each char with bitmask
 * @complexity Time: O(n), Space: O(1) - 26 chars max
 */
class Solution final {
public:
    [[nodiscard]] static string removeDuplicateLetters(const string& s) {
        const int n = static_cast<int>(s.size());
        int last[26] = {};
        
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        
        string ans;
        int mask = 0;
        
        for (int i = 0; i < n; ++i) {
            const char c = s[i];
            if ((mask >> (c - 'a')) & 1) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                mask ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(c);
            mask |= 1 << (c - 'a');
        }
        return ans;
    }
};
