/**
 * @brief Stack-based duplicate removal
 * @intuition Use string as stack; pop when current matches top
 * @approach Iterate through string, push if different from top, pop if same
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string removeDuplicates(const string& s) {
        string stk;
        for (const char c : s) {
            if (!stk.empty() && stk.back() == c) {
                stk.pop_back();
            } else {
                stk += c;
            }
        }
        return stk;
    }
};
