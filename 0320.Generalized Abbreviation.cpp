/**
 * @brief Generate all generalized abbreviations of a word
 * @intuition Either keep char or replace consecutive chars with count
 * @approach DFS trying both options at each position
 * @complexity Time: O(n * 2^n), Space: O(n) for recursion
 */
#include <functional>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<std::string> generateAbbreviations(const std::string& word) const {
        const int n = static_cast<int>(word.size());
        
        std::function<std::vector<std::string>(int)> dfs = [&](int i) -> std::vector<std::string> {
            if (i >= n) {
                return {""};
            }
            
            std::vector<std::string> ans;
            
            // Keep current character
            for (const auto& s : dfs(i + 1)) {
                ans.emplace_back(std::string(1, word[i]) + s);
            }
            
            // Abbreviate starting from current position
            for (int j = i + 1; j <= n; ++j) {
                for (const auto& s : dfs(j + 1)) {
                    const std::string prefix = j < n ? std::string(1, word[j]) : "";
                    ans.emplace_back(std::to_string(j - i) + prefix + s);
                }
            }
            return ans;
        };
        
        return dfs(0);
    }
};
