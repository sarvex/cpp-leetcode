/**
 * @brief Maximize children satisfied by assigning cookies
 * @intuition Greedy: smallest cookie to least greedy satisfiable child
 * @approach Sort both arrays, match smallest sufficient cookie to each child
 * @complexity Time: O(n log n + m log m) Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findContentChildren(std::vector<int>& g, std::vector<int>& s) const -> int {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        const int m = static_cast<int>(g.size());
        const int n = static_cast<int>(s.size());

        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && s[j] < g[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }

        return m;
    }
};
