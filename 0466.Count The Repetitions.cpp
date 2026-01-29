/**
 * @brief Count how many times s2 repeated n2 times fits in s1 repeated n1 times
 * @intuition Precompute transitions: starting position -> (count, end position) after one s1
 * @approach Simulate n1 repetitions of s1, track s2 completions
 * @complexity Time: O(|s1| * |s2| + n1) Space: O(|s2|)
 */
#include <string>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto getMaxRepetitions(const std::string& s1, int n1,
                                          const std::string& s2, int n2) const -> int {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());

        std::vector<std::pair<int, int>> d;

        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == n) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt, j);
        }

        int ans = 0;
        for (int j = 0; n1 > 0; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }

        return ans / n2;
    }
};
