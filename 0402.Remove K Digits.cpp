/**
 * @brief Remove k digits from number to get smallest possible result
 * @intuition Remove larger digits when followed by smaller ones (monotonic stack)
 * @approach Use stack to maintain increasing sequence, remove from end if k remains
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto removeKdigits(const std::string& num, int k) -> std::string {
        std::string stk;

        for (const char c : num) {
            while (k > 0 && !stk.empty() && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            stk += c;
        }

        while (k-- > 0) {
            stk.pop_back();
        }

        std::size_t i = 0;
        while (i < stk.size() && stk[i] == '0') {
            ++i;
        }

        std::string ans = stk.substr(i);
        return ans.empty() ? "0" : ans;
    }
};
