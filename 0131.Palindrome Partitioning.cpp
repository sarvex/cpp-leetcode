/**
 * @brief Find all palindrome partitions using backtracking with DP precomputation
 * @intuition Precompute palindrome checks, then backtrack through all valid partitions
 * @approach DP table for O(1) palindrome check, backtracking for enumeration
 * @complexity Time: O(n * 2^n), Space: O(n^2)
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto partition(const string& s) -> vector<vector<string>> {
        const int n = static_cast<int>(s.size());

        // Precompute palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                isPalin[i][j] = (s[i] == s[j]) && isPalin[i + 1][j - 1];
            }
        }

        vector<vector<string>> ans;
        vector<string> current;

        auto dfs = [&](this auto&& dfs, int start) -> void {
            if (start == n) {
                ans.emplace_back(current);
                return;
            }
            for (int end = start; end < n; ++end) {
                if (isPalin[start][end]) {
                    current.emplace_back(s.substr(start, end - start + 1));
                    dfs(end + 1);
                    current.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};
