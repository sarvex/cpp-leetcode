/**
 * @brief Hash rows by normalized pattern to find max matching rows
 * @intuition Rows matching after flips share same normalized pattern
 * @approach Normalize rows (XOR with first element), count pattern frequencies
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxEqualRowsAfterFlips(const vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        int ans = 0;
        for (const auto& row : matrix) {
            string s;
            for (const int x : row) {
                s.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};
