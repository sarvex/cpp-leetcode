/**
 * @brief Two-pointer comparison for stretchy words
 * @intuition A word is stretchy if character groups can be extended to length >= 3
 * @approach Compare character groups between base string and each word. A group in
 *           word can match if same character and either counts equal or base count >= 3.
 * @complexity Time: O(n * max(|s|, |word|)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto expressiveWords(const std::string& s,
                                               const std::vector<std::string>& words) -> int {
        auto check = [](const std::string& s, const std::string& t) -> bool {
            const int m = static_cast<int>(s.size());
            const int n = static_cast<int>(t.size());
            if (n > m) return false;
            
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] != t[j]) return false;
                
                int k = i;
                while (k < m && s[k] == s[i]) ++k;
                const int c1 = k - i;
                i = k;
                
                k = j;
                while (k < n && t[k] == t[j]) ++k;
                const int c2 = k - j;
                j = k;
                
                if (c1 < c2 || (c1 < 3 && c1 != c2)) return false;
            }
            return i == m && j == n;
        };
        
        int ans = 0;
        for (const auto& t : words) {
            ans += check(s, t);
        }
        return ans;
    }
};
