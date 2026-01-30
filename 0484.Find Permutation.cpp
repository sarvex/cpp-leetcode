/**
 * @brief Find smallest permutation matching increase/decrease pattern
 * @intuition Start with sorted array, reverse segments for consecutive 'D's
 * @approach Scan for 'D' sequences, reverse corresponding range in result
 * @complexity Time: O(n), Space: O(n)
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findPermutation(const std::string& s) const -> std::vector<int> {
        const int n = static_cast<int>(s.size());
        std::vector<int> ans(n + 1);
        std::iota(ans.begin(), ans.end(), 1);

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == 'D') {
                ++j;
            }
            std::reverse(ans.begin() + i, ans.begin() + j + 1);
            i = std::max(i + 1, j);
        }

        return ans;
    }
};
