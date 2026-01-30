/**
 * @brief Backtracking to match pattern with string
 * @intuition Try all possible substrings for each pattern char
 * @approach DFS with backtracking, track char->string and used strings
 * @complexity Time: O(n^m) where m is pattern length, Space: O(m)
 */
class Solution final {
public:
    [[nodiscard]] static bool wordPatternMatch(const string& pattern, const string& s) {
        unordered_set<string> used;
        unordered_map<char, string> mapping;
        return dfs(0, 0, pattern, s, used, mapping);
    }

private:
    [[nodiscard]] static bool dfs(int i, int j, const string& p, const string& s,
                                   unordered_set<string>& used,
                                   unordered_map<char, string>& mapping) {
        const int m = static_cast<int>(p.size());
        const int n = static_cast<int>(s.size());
        
        if (i == m && j == n) {
            return true;
        }
        if (i == m || j == n || m - i > n - j) {
            return false;
        }
        
        const char c = p[i];
        for (int k = j + 1; k <= n; ++k) {
            const string t = s.substr(j, k - j);
            if (mapping.contains(c) && mapping[c] == t) {
                if (dfs(i + 1, k, p, s, used, mapping)) {
                    return true;
                }
            }
            if (!mapping.contains(c) && !used.contains(t)) {
                mapping[c] = t;
                used.insert(t);
                if (dfs(i + 1, k, p, s, used, mapping)) {
                    return true;
                }
                used.erase(t);
                mapping.erase(c);
            }
        }
        return false;
    }
};
