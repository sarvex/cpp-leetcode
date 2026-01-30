/**
 * @brief Minimum flips for monotone increasing binary string
 * @intuition Find optimal split point between 0s and 1s
 * @approach Count total 0s; track flips needed for each prefix of 1s
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minFlipsMonoIncr(const string& s) {
        const int tot = static_cast<int>(count(s.begin(), s.end(), '0'));
        int ans = tot, cur = 0;
        for (int i = 1; i <= static_cast<int>(s.size()); ++i) {
            cur += s[i - 1] == '0';
            ans = min(ans, i - cur + tot - cur);
        }
        return ans;
    }
};
