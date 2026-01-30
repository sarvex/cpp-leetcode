/**
 * @brief Calculate exclusive execution time for each function
 * @intuition Use stack to track active functions, account for nested calls
 * @approach Parse logs, use stack to track current function, update times on start/end
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> exclusiveTime(const int n, const vector<string>& logs) {
        vector<int> ans(n);
        stack<int> stk;
        int pre = 0;
        
        for (const auto& log : logs) {
            int i, cur;
            char c[10];
            sscanf(log.c_str(), "%d:%[^:]:%d", &i, c, &cur);
            
            if (c[0] == 's') {
                if (!stk.empty()) {
                    ans[stk.top()] += cur - pre;
                }
                stk.push(i);
                pre = cur;
            } else {
                ans[stk.top()] += cur - pre + 1;
                stk.pop();
                pre = cur + 1;
            }
        }
        return ans;
    }
};
