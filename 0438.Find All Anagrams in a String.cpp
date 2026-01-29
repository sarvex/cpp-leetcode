/**
 * @brief Find all start indices of p's anagrams in s
 * @intuition Sliding window of size len(p), compare character counts
 * @approach Maintain window count, slide and compare with target count
 * @complexity Time: O(m + n) Space: O(1) - fixed 26 chars
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findAnagrams(const std::string& s, const std::string& p) const
        -> std::vector<int> {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(p.size());
        std::vector<int> ans;

        if (m < n) {
            return ans;
        }

        std::vector<int> cnt1(26, 0);
        for (const char c : p) {
            ++cnt1[c - 'a'];
        }

        std::vector<int> cnt2(26, 0);
        for (int i = 0; i < n - 1; ++i) {
            ++cnt2[s[i] - 'a'];
        }

        for (int i = n - 1; i < m; ++i) {
            ++cnt2[s[i] - 'a'];
            if (cnt1 == cnt2) {
                ans.push_back(i - n + 1);
            }
            --cnt2[s[i - n + 1] - 'a'];
        }

        return ans;
    }
};
