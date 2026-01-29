/**
 * @brief Check if string can be segmented into dictionary words using DP
 * @intuition dp[i] = true if s[0..i) can be formed from dictionary words
 * @approach For each position, check if any valid prefix + dict word reaches it
 * @complexity Time: O(n^2 * m), Space: O(n + dict size) where m = word length
 */

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto wordBreak(const string& s, vector<string>& wordDict) -> bool {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        const int n = static_cast<int>(s.size());

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && words.contains(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
