/**
 * @brief Two-pass scan for shortest distance to target character
 * @intuition Minimum distance is from nearest left or right occurrence
 * @approach First pass left-to-right: track last seen position of target char.
 *           Second pass right-to-left: track next occurrence. Take minimum.
 * @complexity Time: O(n), Space: O(n) for output
 */
class Solution final {
public:
    [[nodiscard]] static auto shortestToChar(const std::string& s, char c)
        -> std::vector<int> {
        const int n = static_cast<int>(s.size());
        constexpr int inf = 1 << 30;
        std::vector<int> ans(n, inf);
        
        for (int i = 0, pre = -inf; i < n; ++i) {
            if (s[i] == c) {
                pre = i;
            }
            ans[i] = std::min(ans[i], i - pre);
        }
        
        for (int i = n - 1, suf = inf; i >= 0; --i) {
            if (s[i] == c) {
                suf = i;
            }
            ans[i] = std::min(ans[i], suf - i);
        }
        return ans;
    }
};
