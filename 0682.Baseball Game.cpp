/**
 * @brief Calculate baseball game score with special operations
 * @intuition Use stack to track valid scores, apply operations accordingly
 * @approach Process operations: numbers push, + sums top 2, D doubles top, C removes top
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int calPoints(const vector<string>& operations) {
        vector<int> stk;
        
        for (const auto& op : operations) {
            const int n = stk.size();
            if (op == "+") {
                stk.push_back(stk[n - 1] + stk[n - 2]);
            } else if (op == "D") {
                stk.push_back(stk[n - 1] << 1);
            } else if (op == "C") {
                stk.pop_back();
            } else {
                stk.push_back(stoi(op));
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
