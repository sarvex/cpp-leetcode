/**
 * @brief Assign parentheses to two groups based on depth parity
 * @intuition Balance depth by alternating group assignment based on current nesting level
 * @approach Track depth counter. Opening parentheses at odd depth go to group 1, even to group 0.
 *           Closing parentheses use the decremented depth to determine their group.
 * @complexity Time: O(n), Space: O(n) for result
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> maxDepthAfterSplit(const string& seq) {
        const int n = seq.size();
        vector<int> ans(n);
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ans[i] = x++ & 1;
            } else {
                ans[i] = --x & 1;
            }
        }
        return ans;
    }
};
