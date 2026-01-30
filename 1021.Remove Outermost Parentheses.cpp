/**
 * @brief Track depth to skip outermost parentheses
 * @intuition Outermost parens are at depth 0 going in and depth 1 going out
 * @approach Count depth, include character only when depth > 0 for '(' and depth > 1 for ')'
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string removeOuterParentheses(const string& s) {
        string ans;
        int cnt = 0;
        for (const char c : s) {
            if (c == '(') {
                if (++cnt > 1) {
                    ans.push_back(c);
                }
            } else {
                if (--cnt) {
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};
