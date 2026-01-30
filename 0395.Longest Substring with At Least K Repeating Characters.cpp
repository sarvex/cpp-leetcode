/**
 * @brief Find longest substring where each char appears at least k times
 * @intuition Split on chars with frequency < k, recursively check substrings
 * @approach Divide and conquer: use infrequent chars as split points
 * @complexity Time: O(n * 26), Space: O(n) recursion
 */
class Solution final {
public:
    [[nodiscard]] static auto longestSubstring(const std::string& s, int k) -> int {
        std::function<int(int, int)> dfs = [&](int l, int r) -> int {
            int cnt[26]{};
            for (int i = l; i <= r; ++i) {
                ++cnt[s[i] - 'a'];
            }

            char split = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0 && cnt[i] < k) {
                    split = static_cast<char>('a' + i);
                    break;
                }
            }

            if (split == 0) {
                return r - l + 1;
            }

            int i = l;
            int ans = 0;
            while (i <= r) {
                while (i <= r && s[i] == split) {
                    ++i;
                }
                if (i > r) {
                    break;
                }
                int j = i;
                while (j <= r && s[j] != split) {
                    ++j;
                }
                ans = std::max(ans, dfs(i, j - 1));
                i = j;
            }

            return ans;
        };

        return dfs(0, static_cast<int>(s.size()) - 1);
    }
};
