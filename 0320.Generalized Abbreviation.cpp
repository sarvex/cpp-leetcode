/**
 * @brief Generate all generalized abbreviations of a word
 * @intuition Either keep char or replace consecutive chars with count
 * @approach DFS trying both options at each position
 * @complexity Time: O(n * 2^n), Space: O(n) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> generateAbbreviations(const string& word) {
        const int n = static_cast<int>(word.size());
        
        function<vector<string>(int)> dfs = [&](int i) -> vector<string> {
            if (i >= n) {
                return {""};
            }
            
            vector<string> ans;
            
            for (const auto& s : dfs(i + 1)) {
                ans.emplace_back(string(1, word[i]) + s);
            }
            
            for (int j = i + 1; j <= n; ++j) {
                for (const auto& s : dfs(j + 1)) {
                    const string prefix = j < n ? string(1, word[j]) : "";
                    ans.emplace_back(to_string(j - i) + prefix + s);
                }
            }
            return ans;
        };
        
        return dfs(0);
    }
};
