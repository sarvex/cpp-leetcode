/**
 * @brief Greedy decomposition into maximum palindromic chunks
 * @intuition Match shortest possible prefix with suffix, then recurse on middle
 * @approach Use two pointers from both ends. Find shortest matching prefix/suffix pair,
 *           count 2 chunks, and continue inward. If unmatched middle remains, count 1.
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int longestDecomposition(const string& text) {
        int ans = 0;
        auto check = [&](int i, int j, int k) -> bool {
            while (k--) {
                if (text[i++] != text[j++]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0, j = text.size() - 1; i <= j;) {
            bool ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (check(i, j - k + 1, k)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ans += 1;
                break;
            }
        }
        return ans;
    }
};
