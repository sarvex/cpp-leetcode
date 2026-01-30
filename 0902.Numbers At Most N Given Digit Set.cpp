/**
 * @brief Digit DP to count numbers at most N using given digits
 * @intuition Use digit DP with leading zero and limit tracking
 * @approach For each position, try valid digits respecting the limit constraint;
 *           memoize results when not at leading zeros or limit
 * @complexity Time: O(d * m), Space: O(m) where d is digits size, m is number length
 */
class Solution final {
public:
    [[nodiscard]] static int atMostNGivenDigitSet(const vector<string>& digits, const int n) {
        const string s = to_string(n);
        unordered_set<int> nums;
        for (const auto& x : digits) {
            nums.insert(stoi(x));
        }
        const int m = static_cast<int>(s.size());
        vector<int> f(m, -1);
        auto dfs = [&](this auto&& dfs, int i, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ? 0 : 1;
            }
            if (!lead && !limit && f[i] != -1) {
                return f[i];
            }
            const int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 && lead) {
                    ans += dfs(i + 1, true, limit && j == up);
                } else if (nums.contains(j)) {
                    ans += dfs(i + 1, false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i] = ans;
            }
            return ans;
        };
        return dfs(0, true, true);
    }
};
