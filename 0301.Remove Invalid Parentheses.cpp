/**
 * @brief DFS with pruning to remove minimum invalid parentheses
 * @intuition Count mismatched left/right parentheses, then DFS to remove exactly that many
 * @approach Use DFS to try removing each '(' or ')' while pruning invalid branches
 * @complexity Time: O(2^n) worst case, Space: O(n) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> removeInvalidParentheses(const string& s) {
        unordered_set<string> ans;
        int left = 0;
        int right = 0;
        const int n = static_cast<int>(s.size());
        
        for (const char c : s) {
            if (c == '(') {
                ++left;
            } else if (c == ')') {
                if (left > 0) {
                    --left;
                } else {
                    ++right;
                }
            }
        }
        
        function<void(int, int, int, int, int, string)> dfs;
        dfs = [&](int i, int l, int r, int lcnt, int rcnt, string t) {
            if (i == n) {
                if (l == 0 && r == 0) {
                    ans.insert(t);
                }
                return;
            }
            if (n - i < l + r || lcnt < rcnt) {
                return;
            }
            if (s[i] == '(' && l > 0) {
                dfs(i + 1, l - 1, r, lcnt, rcnt, t);
            }
            if (s[i] == ')' && r > 0) {
                dfs(i + 1, l, r - 1, lcnt, rcnt, t);
            }
            const int x = s[i] == '(' ? 1 : 0;
            const int y = s[i] == ')' ? 1 : 0;
            dfs(i + 1, l, r, lcnt + x, rcnt + y, t + s[i]);
        };

        dfs(0, left, right, 0, 0, "");
        return vector<string>(ans.begin(), ans.end());
    }
};
