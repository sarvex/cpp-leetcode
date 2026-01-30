/**
 * @brief Track depth and score atomic pairs at each level
 * @intuition "()" at depth d contributes 2^d; nested structure doubles inner scores
 * @approach Track current depth. When closing a "()", if it's an atomic pair,
 *           add 2^(depth-1) to result. Depth naturally handles nesting.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto scoreOfParentheses(const std::string& s) -> int {
        int ans = 0, d = 0;
        const int n = static_cast<int>(s.size());
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++d;
            } else {
                --d;
                if (s[i - 1] == '(') {
                    ans += 1 << d;
                }
            }
        }
        return ans;
    }
};
