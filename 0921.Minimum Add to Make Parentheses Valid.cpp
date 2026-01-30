/**
 * @brief Count minimum additions for valid parentheses
 * @intuition Track unmatched open and close parentheses
 * @approach Use stack simulation; count unmatched after processing
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minAddToMakeValid(const string& s) {
        string stk;
        for (const char c : s) {
            if (c == ')' && !stk.empty() && stk.back() == '(') {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return static_cast<int>(stk.size());
    }
};
